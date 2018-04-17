#include "dailyLateReportController.h"

Error dailyLateReportController:: validateModel(dailyLateReportModel dailylatereportModel)
{
    Error error  ;//= new Error();


    if(dailylatereportModel.getEmployeeID() == "")
    {
        error.setErrorCode( "CEDLR1");
        error.setErrorMsg("Empty employee id!");
        return error;
    }

    if(dailylatereportModel.getAdminID() == "")
    {
        error.setErrorCode( "CEDLR2");
        error.setErrorMsg( "Empty admin id!");
        return error;
    }

    if(dailylatereportModel.getEmployeeDep() == "")
    {
        error.setErrorCode("CEDLR3");
        error.setErrorMsg("Empty employeeDep id!");
        return error;
    }

    if( dailylatereportModel.getLateTime() == "")
    {
        error.setErrorCode( "CEDLR4");
        error.setErrorMsg("Late time is empty!");
        return error;
    }
    else if(dailylatereportModel.getLateTime().toInt() <= 0)
    {
        error.setErrorCode( "CEDLR4");
        error.setErrorMsg("Late time is negative!");
        return error;
    }
    else if(dailylatereportModel.getLateTime().contains("[a-zA-Z]+") )
    {
        error.setErrorCode("CEDLR4");
        error.setErrorMsg("late time contains CHARS!");
        return error;
    }

    if(dailylatereportModel.getDateOfLate() == QDateTime())//add the default value here for QDateTime
    {
        error.setErrorCode("CEDLR5");
        error.setErrorMsg("Date of late is empty!");
        return error;
    }

    if(dailylatereportModel.getAmount() == "")
    {
        error.setErrorCode( "CEDLR6");
        error.setErrorMsg( "Amount is empty!");
        return error;

    }
    else if(dailylatereportModel.getAmount().toDouble() <= 0.0)
    {
        error.setErrorCode( "CEDLR4");
        error.setErrorMsg( "Amount is negative!");
        return error;
    }
    else if(dailylatereportModel.getLateTime().contains("[a-zA-Z]+") )
    {
        error.setErrorCode( "CEDLR4");
        error.setErrorMsg("Amount contains CHARS!");
        return error;
    }

    if(dailylatereportModel.getReasons() == "")
    {
        error.setErrorCode( "CEDLR7");
        error.setErrorMsg("Reasons id!");
        return error;
    }

    //send to repo
    error.setErrorCode( "Yes!");
    error.setErrorMsg("success! coloian 5555");
    return error;
}
