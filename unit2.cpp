#include <QDebug>

#include "unit2.h"


Unit2::Unit2(System * system) : Unit("Unit 2", system)
{
    qDebug() << "Unit2";
}
