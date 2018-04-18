#ifndef MODIFYSALARYCONTROLLER_H
#define MODIFYSALARYCONTROLLER_H
#include <QMap>
#include <QVariant>
#include <model/employee/modifysalarymodel.h>
#include <controller/employee/error.h>
#include <repositories/employeerepository.h>


class modifysalarycontroller
{
public:
    Error validateModel(modifySalaryModel modifysalarymodel);
    QMap <QString,QVariant> getAttributeNotDefault(modifySalaryModel modify);


};

#endif // MODIFYSALARYCONTROLLER_H
