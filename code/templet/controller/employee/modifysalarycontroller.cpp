#include "modifysalarycontroller.h"
#include <model/employee/modifysalarymodel.h>

Error modifysalarycontroller::validateModel(modifySalaryModel modifysalarymodel)
{
    Error error;
    if(modifysalarymodel.getEmployeeID() == "")
    {
        error.setErrorCode("MSCVM1" );
        error.setErrorMsg("employee id is empty!");
        return error;
    }
    if(modifysalarymodel.getAdminID() == "")
    {
        error.setErrorCode("MSCVM2" );
        error.setErrorMsg("admin id is empty!");
        return error;
    }
    if(modifysalarymodel.getType() == ' ')
    {
        error.setErrorCode("MSCVM4" );
        error.setErrorMsg("type is empty!");
        return error;
    }
    else if(modifysalarymodel.getType() != 'd'&& modifysalarymodel.getType() !='z' && modifysalarymodel.getType() != 's')
    {
        error.setErrorCode("MSCVM4" );
        error.setErrorMsg("invalid type,it must be (d, z or s) !");
        return error;
    }
    if(modifysalarymodel.getAmount() == 0.0)
    {
        error.setErrorCode("MSCVM5" );
        error.setErrorMsg("amount is empty!");
        return error;
    }
    if(modifysalarymodel.getAmount() < 0.0)
    {
        error.setErrorCode("MSCVM5") ;
        error.setErrorMsg("amount is negative!");
        return error;
    }
    if(modifysalarymodel.getReason() =="")
    {
        error.setErrorCode("MSCVM6") ;
        error.setErrorMsg("reason is empty!");
        return error;
    }
    //send to repo
    employeeRepository empRepo;
    empRepo.addModification(modifysalarymodel);

    error.setErrorCode( "Yes!");
    error.setErrorMsg("success! coloian 55555");
    return error;

}

QMap <QString,QVariant> modifysalarycontroller :: getAttributeNotDefault(modifySalaryModel modify)
{
    QMap<QString,QVariant> Attribute;

    if( modify.getAdminID() != "" )
    {
        Attribute.insert("Uid", modify.getAdminID());
    }
    if( modify.getAmount() != 0.0 )
    {
        Attribute.insert("amount", modify.getAmount());
    }
    if( modify.getReason() != "" )
    {
        Attribute.insert("Reasons", modify.getReason());
    }

    return Attribute;
}
