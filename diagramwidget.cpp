#include <QEvent>
#include <QResizeEvent>
#include <QDebug>
#include <math.h>

#include "diagramwidget.h"


DiagramWidget::DiagramWidget(QWidget *parent) : QGraphicsView(parent)
{
    setDragMode(NoDrag);
    setCacheMode(CacheBackground);
    setTransformationAnchor(AnchorViewCenter);
    setResizeAnchor(AnchorViewCenter);
    setViewportUpdateMode(SmartViewportUpdate);
    setFrameShape(QFrame::NoFrame);
}

void DiagramWidget::wheelEvent(QWheelEvent *e)
{
    if ( e->modifiers() == Qt::ControlModifier )
    {
        qDebug() << "wheelEvent";

        if ( e->delta() > 0 )
            zoomIn();
        else
            zoomOut();
    }
}

void DiagramWidget::zoomIn()
{
    if ( viewRect().width() > 0.1 )
    {
        scale(sqrt(2.0), sqrt(2.0));
        fitInView(sceneRect(), Qt::KeepAspectRatio);
        viewport()->update();
    }
}

void DiagramWidget::zoomOut()
{
    if ( !viewRect().contains(sceneRect()) )
    {
        scale(sqrt(0.5), sqrt(0.5));
        fitInView(sceneRect(), Qt::KeepAspectRatio);
        viewport()->update();
    }
}

bool DiagramWidget::event(QEvent *event)
{
    if ( event->type() == QEvent::WindowActivate )
    {
        qDebug() << "DiagramWidget::event" << event << sceneRect();
        fitInView(sceneRect(), Qt::KeepAspectRatio);
        viewport()->update();
    }
    return QGraphicsView::event(event);
}

QRectF DiagramWidget::viewRect() const
{
    return QRectF(mapToScene(viewport()->geometry().topLeft()),
                  mapToScene(viewport()->geometry().bottomRight()));
}
