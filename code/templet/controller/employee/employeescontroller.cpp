#include "employeesController.h"

QMap <QString,QVariant> employeesController:: getAttributeNotDefault(employeesModel employee)
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

    if(employee.getSSN() != "")
    {
        Attribute.insert("SSN", employee.getSSN());
    }

    if(employee.getPreferedName()!="")
    {
        Attribute.insert("NickName", employee.getPreferedName());
    }

    if(employee.getDateBirth()!=QDate(0,0,0))
    {
        Attribute.insert("BirthDate",employee.getDateBirth());
    }

    if(employee.getAddress()!="")
    {
        Attribute.insert("Address", employee.getAddress());
    }

    if(employee.getPhoneNumber()!="")
    {
        Attribute.insert("PhoneNum", employee.getPhoneNumber());
    }

    if(employee.getEmail()!="")
    {
        Attribute.insert("Email", employee.getEmail());
    }

    if(employee.getShiftBegTime()!=QTime(0,0,0,0) )
    {
        Attribute.insert("ShiftBeg", employee.getShiftBegTime());
    }

    if(employee.getShiftEndTime()!=QTime(0,0,0,0))
    {
        Attribute.insert("ShiftEnd", employee.getShiftEndTime());
    }

    if(employee.getSalary()!=0.0)
    {
        Attribute.insert("ClearSalary", employee.getSalary());
    }

    if(employee.getQualification()!="")
    {
        Attribute.insert("Certti", employee.getQualification());
    }

    return Attribute;
}
