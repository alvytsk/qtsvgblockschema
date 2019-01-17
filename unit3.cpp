#include <QDebug>

#include "unit3.h"


Unit3::Unit3(System * system) : Unit("Unit 3", system)
{
    qDebug() << "Unit3";
}
