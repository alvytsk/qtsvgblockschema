#include <QSvgRenderer>
#include <QGraphicsRectItem>
#include <QtDebug>

#include "system.h"
#include "unit1.h"
#include "unit2.h"
#include "unit3.h"

System::System()
{
    QString resource = ":/diagram/test2";
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
        setBrush(QColor(139,195,74)); //100, 221, 23 - good green!
    else {                              //255, 152, 0 - orange
        setBrush(QColor(255, 152, 0)); //244, 67,  54 - red
    }

    state = !state;
}

Unit::Unit(const QString & id, System * system)
{
    m_rect = system->diagram()->renderer()->boundsOnElement(id);
    qDebug() << id << m_rect;

    QMatrix transform = system->diagram()->renderer()->matrixForElement(id);
    m_rect = transform.mapRect(m_rect);
    qDebug() << m_rect;

    m_item = new UnitItem(m_rect);
    m_item->setZValue(-1);
    m_item->setPen(QPen(Qt::NoPen));
    m_item->setBrush(QColor(244,67,54));
    system->scene()->addItem(m_item);

    m_text = new QGraphicsSimpleTextItem();
    system->scene()->addItem(m_text);
}

void Unit::setText(const QString & text)
{
    m_text->setText(text);
    adjustText();
}

void Unit::adjustText()
{
    QRectF bound = m_text->boundingRect();
    QPointF offset(bound.width()/2, bound.height()/2);
    QFont font;
    font.setFamily("Helvetica");
    font.setWeight(QFont::Normal);
    m_text->setFont(font);
    m_text->setPos(m_rect.center() - offset);
}
