#include <QDebug>

#include "unit1.h"


Unit1::Unit1(System * system) : Unit("Unit 1", system)
{
    qDebug() << "Unit1";
}
