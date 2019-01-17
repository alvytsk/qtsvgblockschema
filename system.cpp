#include <QSvgRenderer>
#include <QGraphicsRectItem>
#include <QtDebug>

#include "system.h"
#include "unit1.h"
#include "unit2.h"
#include "unit3.h"

System::System()
{
    QString resource = ":/diagram/test";
    m_diagram = new QGraphicsSvgItem(resource);

    m_scene = new QGraphicsScene();
    m_scene->addItem(m_diagram);

    qDebug() << m_diagram;

    unit1 = new Unit1(this);
    unit2 = new Unit2(this);
    unit3 = new Unit3(this);
}

QGraphicsScene * System::scene()
{
    return m_scene;
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
    qDebug() << id;

    m_rect = system->diagram()->renderer()->boundsOnElement(id);
    qDebug() << m_rect;

    QMatrix transform = system->diagram()->renderer()->matrixForElement(id);
    m_rect = transform.mapRect(m_rect);

    qDebug() << m_rect;

    m_item = new UnitItem(m_rect);
    m_item->setZValue(-1);
    m_item->setPen(QPen(Qt::NoPen));
    m_item->setBrush(QColor(255,0,0));
    system->scene()->addItem(m_item);

    m_text = new QGraphicsTextItem();
    system->scene()->addItem(m_text);
}
