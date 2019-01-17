#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    display = new DiagramWidget(ui->centralWidget);

    system = new System();
    unit1 = new Unit1(system);
    unit2 = new Unit2(system);
    unit3 = new Unit3(system);

    display->setScene(system->scene());
}

MainWindow::~MainWindow()
{
    delete ui;
}
