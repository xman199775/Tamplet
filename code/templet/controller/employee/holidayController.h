#ifndef HOLIDAYCONTROLLER_H
#define HOLIDAYCONTROLLER_H
#include <QMap>
#include <QVariant>
#include <model/employee/holidayModel.h>

class holidayController
{
    public:
    QString validateModel(holidayModel holidaymodel);
    QMap <QString,QVariant> getAttributeNotDefault(holidayModel holiday);

};

#endif // HOLIDAYCONTROLLER_H
