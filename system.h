#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsRectItem>

class System : public QObject
{
    Q_OBJECT

public:
    explicit System();
    QGraphicsScene * scene();
    const QGraphicsSvgItem * diagram() const;

private:
    QGraphicsScene m_scene;
    QGraphicsSvgItem * m_diagram;
};


///
class UnitItem : public QGraphicsRectItem
{
    friend class Unit;

public:
    UnitItem(const QRectF &);
    ~UnitItem();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    QRectF m_rect;
    bool state;
};


///
class Unit : public QObject
{
    Q_OBJECT

public:
    Unit(const QString & id, System *);

private:
    QRectF m_rect;
    UnitItem * m_item;
    QGraphicsTextItem * m_text;
};

#endif // SYSTEM_H
