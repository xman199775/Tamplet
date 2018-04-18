#ifndef HOLIDAYCONTROLLER_H
#define HOLIDAYCONTROLLER_H
#include <QMap>
#include <QVariant>
#include <model/employee/holidayModel.h>
#include <controller/employee/error.h>
#include <repositories/employeerepository.h>

class holidayController
{
    public:
    Error validateModel(holidayModel holidaymodel);
    QMap <QString,QVariant> getAttributeNotDefault(holidayModel holiday);

};

#endif // HOLIDAYCONTROLLER_H
