#include "efficiencycontroller.h"

efficiencycontroller::efficiencycontroller()
{

}

Error validateModel(efficiencymodel effmodel)
{
    Error error;

    if(effmodel.getEmpId() == "")
    {
        error.setErrorCode("EFCVM1") ;
        error.setErrorMsg("employee id is empty");
        return error;
    }
    if(effmodel.getAdminId() == "")
    {
        error.setErrorCode("EFCVM2") ;
        error.setErrorMsg("admin id is empty");
        return error;
    }
    if(effmodel.getAmount() == 0.0)
    {
        error.setErrorCode("EFCVM3");
        error.setErrorMsg("amount is empty!");
        return error;
    }
    else if(effmodel.getAmount() < 0.0)
    {
        error.setErrorCode("EFCVM3") ;
        error.setErrorMsg("amount is negative!");
        return error;
    }

    //send to repo
    employeeRepository repo;
    repo.addEfficiency(effmodel);

    error.setErrorCode( "Yes!");
    error.setErrorMsg("success! coloian 55555");
    return error;
}

QMap <QString,QVariant> efficiencycontroller:: getAttributeNotDefault(efficiencymodel efficiency)
{
     QMap<QString,QVariant> Attribute;

     if(efficiency.getEmpId() != "")
     {
         Attribute.insert("empId", efficiency.getEmpId());
     }
     if(efficiency.getAdminId() != "")
     {
         Attribute.insert("adminId", efficiency.getAdminId());
     }
     if(efficiency.getAmount() != 0.0)
     {
         Attribute.insert("amount", efficiency.getAmount());
     }
     if(efficiency.getDate() != QDateTime(QDate(0,0,0)))
     {
         Attribute.insert("date", efficiency.getDate());
     }

     return Attribute;
}
