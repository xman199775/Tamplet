#ifndef EMPLOYEESCONTROLLER_H
#define EMPLOYEESCONTROLLER_H
#include <QMap>
#include <QVariant>
#include<model/employee/employeesModel.h>
#include <controller/employee/error.h>
#include <repositories/employeerepository.h>
class employeesController
{
    public:
    Error validateModel(employeesModel employeesmodel);
    QMap <QString,QVariant> getAttributeNotDefault(employeesModel employee);


};

#endif // EMPLOYEESCONTROLLER_H
