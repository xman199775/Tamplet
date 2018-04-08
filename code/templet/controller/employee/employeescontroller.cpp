#include "employeesController.h"

QMap <QString,QVariant> employeesController:: getAttributeNotDiffualt(employeesModel employee)
{
    QMap<QString,QVariant> Attribute;
    if(employee.getEmpId()!="")
    {
        Attribute.insert("Empid",employee.getEmpId());
    }
    if(employee.getEmployeeName()!="")
    {
        Attribute.insert("Name",employee.getEmployeeName());
    }
    if(employee.getDateBirth()!=QDate(0,0,0))
    {
        Attribute.insert("BirthDate",employee.getDateBirth());
    }
    return Attribute;
}
