#include <QEvent>

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

bool DiagramWidget::event(QEvent *event)
{
    if ( event->type() == QEvent::WindowActivate )
    {
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
