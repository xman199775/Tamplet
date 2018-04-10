#ifndef HOLIDAYCONTROLLER_H
#define HOLIDAYCONTROLLER_H
#include <QMap>
#include <QVariant>
#include <model/employee/holidayModel.h>

class holidayController
{
    public:

    QMap <QString,QVariant> getAttributeNotDefault(holidayModel holiday);

};

#endif // HOLIDAYCONTROLLER_H
