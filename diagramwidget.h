#ifndef DIAGRAMWIDGET_H
#define DIAGRAMWIDGET_H

#include <QGraphicsView>

class DiagramWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit DiagramWidget(QWidget *parent = nullptr);

    QRectF viewRect() const;

signals:

protected:
    bool event(QEvent *);

public slots:
};

#endif // DIAGRAMWIDGET_H
