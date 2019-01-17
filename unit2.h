#ifndef UNIT2_H
#define UNIT2_H

#include <QObject>

#include "system.h"

class Unit2 : public Unit
{
    Q_OBJECT

public:
    Unit2(System *);
};

#endif // UNIT2_H
