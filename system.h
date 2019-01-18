#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

class Unit1;
class Unit2;
class Unit3;

class System : public QObject
{
    Q_OBJECT

public:
    explicit System();
    QGraphicsScene * scene();
    const QGraphicsSvgItem * diagram() const;

private:
    QGraphicsScene * m_scene;
    QGraphicsSvgItem * m_diagram;

    Unit1 * unit1;
    Unit2 * unit2;
    Unit3 * unit3;
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
    void setText(const QString &);

public slots:
    void adjustText();

private:
    QRectF m_rect;
    UnitItem * m_item;
    QGraphicsSimpleTextItem * m_text;
};

#endif // SYSTEM_H
