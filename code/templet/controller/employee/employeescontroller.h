#ifndef EMPLOYEESCONTROLLER_H
#define EMPLOYEESCONTROLLER_H
#include <QMap>
#include <QVariant>
#include<model/employee/employeesModel.h>
class employeesController
{
    public:
    QMap <QString,QVariant> getAttributeNotDefault(employeesModel employee);


};

#endif // EMPLOYEESCONTROLLER_H
