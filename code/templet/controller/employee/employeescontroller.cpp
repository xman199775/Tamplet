#include "employeesController.h"

Error employeesController::validateModel(employeesModel employeesmodel)
{
    Error error;
    if(employeesmodel.getEmpId() == "")
    {
        error.setErrorCode("ECVM1") ;
        error.setErrorMsg("employee id is empty");
        return error;
    }
    if(employeesmodel.getEmployeeName() == "")
    {
        error.setErrorCode("ECVM2" );
        error.setErrorMsg("employee name is empty");
        return error;
    }
    if(employeesmodel.getSSN() == "")
    {
        error.setErrorCode("ECVM3" );
        error.setErrorMsg("SSN is empty");
        return error;
    }
    else if(employeesmodel.getSSN().length() > 14)
    {
        error.setErrorCode("ECVM3") ;
        error.setErrorMsg("SSN is more than 14 digit!");
        return error;
    }
    if(employeesmodel.getPreferedName() == "")
    {
        error.setErrorCode("ECVM4" );
        error.setErrorMsg("prefered name is empty");
        return error;
    }
    if(employeesmodel.getAddress() == "")
    {
        error.setErrorCode("ECVM6" );
        error.setErrorMsg("address is empty");
        return error;
    }
    if(employeesmodel.getPhoneNumber() == "")
    {
        error.setErrorCode("ECV7") ;
        error.setErrorMsg("phone number is empty");
        return error;
    }
    else if(employeesmodel.getPhoneNumber().length() > 11 ||employeesmodel.getPhoneNumber()[0] !=0 )//if the number may be global, then should remove this
    {
        error.setErrorCode("ECV7") ;
        error.setErrorMsg("invalid phone number");
        return error;
    }
    if(employeesmodel.getEmail() == "")
    {
        error.setErrorCode("ECVM8") ;
        error.setErrorMsg("email is empty");
        return error;
    }
    else if( ! employeesmodel.getEmail().contains('@'))
    {
        error.setErrorCode("ECVM8") ;
        error.setErrorMsg("invalid email format");
        return error;
    }
    if(employeesmodel.getSalary() == 0.0)
    {
        error.setErrorCode("ECVM11") ;
        error.setErrorMsg("empty salary!");
        return error;
    }
    if(employeesmodel.getSalary() < 0.0)
    {
        error.setErrorCode("ECVM11") ;
        error.setErrorMsg("salary is set to negative!");
        return error;
    }
    if(employeesmodel.getQualification() == "")
    {
        error.setErrorCode("ECVM12") ;
        error.setErrorMsg("empty qualification!");
        return error;
    }

    //send to repo
    employeeRepository empRepo;
    empRepo.addEmployee(employeesmodel);

    error.setErrorCode( "Yes!");
    error.setErrorMsg("success! coloian 55555");
    return error;

}

QMap <QString,QVariant> employeesController:: getAttributeNotDefault(employeesModel employee)
{
    QMap<QString,QVariant> Attribute;

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
