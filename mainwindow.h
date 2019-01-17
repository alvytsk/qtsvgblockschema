#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "diagramwidget.h"
#include "system.h"
#include "unit1.h"
#include "unit2.h"
#include "unit3.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    DiagramWidget * display;
    System * system;

    Unit1 * unit1;
    Unit2 * unit2;
    Unit3 * unit3;
};

#endif // MAINWINDOW_H
