#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    display = new DiagramWidget(ui->centralWidget);
    system = new System();
    display->setScene(system->scene());
    display->scene()->setSceneRect(0,0,400,400);

    qDebug() << display->scene()->sceneRect().size();
}

MainWindow::~MainWindow()
{
    delete ui;
}
