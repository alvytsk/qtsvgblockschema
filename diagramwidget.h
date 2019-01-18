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

public slots:
    void zoomIn();
    void zoomOut();

protected:
    bool event(QEvent *);
    void wheelEvent(QWheelEvent *);
    void resizeEvent ( QResizeEvent * );

public slots:
};

#endif // DIAGRAMWIDGET_H
