#ifndef MODIFYSALARYCONTROLLER_H
#define MODIFYSALARYCONTROLLER_H
#include <QMap>
#include <QVariant>
#include <model/employee/modifysalarymodel.h>


class modifysalarycontroller
{
public:
    QMap <QString,QVariant> getAttributeNotDefault(modifySalaryModel modify);


};

#endif // MODIFYSALARYCONTROLLER_H
