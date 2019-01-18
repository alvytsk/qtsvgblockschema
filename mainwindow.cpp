#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    display = new DiagramWidget();
    system = new System();
    display->setScene(system->scene());
    setCentralWidget(display);

    qDebug() << display->scene()->sceneRect().size();
}

MainWindow::~MainWindow()
{
    delete ui;
}
