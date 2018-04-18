#include "holidayController.h"

Error holidayController::validateModel(holidayModel holidaymodel)
{
    Error error;
    if(holidaymodel.getEmpID() =="" )
    {
        error.setErrorCode("HCVM1") ;
        error.setErrorMsg("employee id is empty");
        return error;
    }
    if(holidaymodel.getAdminID() == "")
    {
        error.setErrorCode("HCVM2") ;
        error.setErrorMsg("admin id is empty");
        return error;
    }
    if(holidaymodel.getLeaveReasons() == "")
    {
        error.setErrorCode("HCVM5") ;
        error.setErrorMsg("Reason is empty");
        return error;
    }
    if(holidaymodel.getLeaveNotes() == "")
    {
        error.setErrorCode("HCVM6" );
        error.setErrorMsg("Notes is empty");
        return error;
    }
    if(holidaymodel.getDisc() == 0.0)
    {
        error.setErrorCode("HCVM7" );
        error.setErrorMsg("discount is empty");
        return error;
    }
    if(holidaymodel.getDisc() <0.0)
    {
        error.setErrorCode("HCVM7") ;
        error.setErrorMsg("discount is negative!");
        return error;
    }

    //send to repo
    employeeRepository empRepo;
    empRepo.addHoliday(holidaymodel);

    error.setErrorCode( "Yes!");
    error.setErrorMsg("success! coloian 55555");
    return error;

}

QMap <QString,QVariant> holidayController::getAttributeNotDefault(holidayModel holiday)
{
    QMap <QString,QVariant> attribute;

    if(holiday.getEmpID() != "")
    {
        attribute.insert("Empid", holiday.getEmpID());
    }
    if(holiday.getAdminID() != "")
    {
        attribute.insert("Uid", holiday.getAdminID());
    }
    if(holiday.getLeaveDate() != QDate(0,0,0))
    {
        attribute.insert("SDate", holiday.getLeaveDate());
    }
    if(holiday.getBackDate() != QDate(0,0,0))
    {
        attribute.insert("EDate", holiday.getBackDate());
    }
    if(holiday.getLeaveReasons() != "")
    {
        attribute.insert("Reason", holiday.getLeaveReasons());
    }
    if(holiday.getLeaveNotes() != "")
    {
        attribute.insert("Notes", holiday.getLeaveNotes());
    }
    if(holiday.getDisc() != 0.0)
    {
        attribute.insert("Disc",holiday.getDisc() );
    }

    return attribute;
}
