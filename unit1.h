#ifndef UNIT1_H
#define UNIT1_H

#include <QObject>

#include "system.h"

class Unit1 : public Unit
{
    Q_OBJECT

public:
    Unit1(System *);
};

#endif // UNIT1_H
