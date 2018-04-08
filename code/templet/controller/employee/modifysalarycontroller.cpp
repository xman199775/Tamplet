#include "modifysalarycontroller.h"
#include <model/employee/modifysalarymodel.h>

QMap <QString,QVariant> modifysalarycontroller :: getAttributeNotDefault(modifySalaryModel modify)
{
    QMap<QString,QVariant> Attribute;

    if( modify.getEmployeeID() != "" )
    {
        Attribute.insert("Empid", modify.getEmployeeID());
    }

    if( modify.getAdminID() != "" )
    {
        Attribute.insert("Uid", modify.getAdminID());
    }
    if( modify.getDateOfModify() !=QDateTime()  )//write the dafault constr. for QDateTime
    {
        Attribute.insert("Date", modify.getDateOfModify());
    }
    if( modify.getAmount() != 0.0 )
    {
        Attribute.insert("amount", modify.getAmount());
    }
    if( modify.getReason() != "" )
    {
        Attribute.insert("Reasons", modify.getReason());
    }
    if( modify.getNewSalary() != 0.0 )
    {
        Attribute.insert("NewSalary", modify.getNewSalary());
    }

    return Attribute;
}
