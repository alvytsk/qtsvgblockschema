#include <QSvgRenderer>
#include <QGraphicsRectItem>
#include <QtDebug>

#include "system.h"

System::System()
{
    QString resource = ":/diagram/test";

    m_diagram = new QGraphicsSvgItem(resource);

    qDebug() << m_diagram;

    m_scene.addItem(m_diagram);
}

QGraphicsScene * System::scene()
{
    return &m_scene;
}

const QGraphicsSvgItem * System::diagram() const
{
    return m_diagram;
}

UnitItem::UnitItem(const QRectF & rect) : QGraphicsRectItem(rect)
{
    state = false;
    m_rect = rect;
}

UnitItem::~UnitItem()
{
    ;
}

void UnitItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if(!state)
        setBrush(QColor(0,255,0));
    else {
        setBrush(QColor(255,0,0));
    }

    state = !state;
}

Unit::Unit(const QString & id, System * system)
{
    m_rect = system->diagram()->renderer()->boundsOnElement(id);

    qDebug() << m_rect;

    QMatrix transform = system->diagram()->renderer()->matrixForElement(id);
    qDebug() << transform;

    m_rect = transform.mapRect(m_rect);
    m_rect.adjust(1.0, 1.0, -1.5, -1.5);

    qDebug() << m_rect;

    m_item = new UnitItem(m_rect);
    m_item->setZValue(-1);
    m_item->setPen(QPen(Qt::NoPen));
    m_item->setBrush(QColor(255,0,0));
    system->scene()->addItem(m_item);

    m_text = new QGraphicsTextItem();
    system->scene()->addItem(m_text);
}
