#include "dailyLateReportController.h"

Error dailyLateReportController:: validateModel(dailyLateReportModel dailylatereportModel)
{
    Error error  ;//= new Error();


    if(dailylatereportModel.getEmployeeID() == "")
    {
        error.setErrorCode( "DLRCVM1");
        error.setErrorMsg("Empty employee id!");
        return error;
    }

    if(dailylatereportModel.getAdminID() == "")
    {
        error.setErrorCode( "DLRCVM2");
        error.setErrorMsg( "Empty admin id!");
        return error;
    }
    if(dailylatereportModel.getAmount() == 0)
    {
        error.setErrorCode( "DLRCVM4");
        error.setErrorMsg( "Amount is empty!");
        return error;

    }
    else if(dailylatereportModel.getAmount() <= 0.0)
    {
        error.setErrorCode( "DLRCVM4");
        error.setErrorMsg( "Amount is negative!");
        return error;
    }
    else if(dailylatereportModel.getAmount() >= dailylatereportModel.getLimit())
    {
        error.setErrorCode( "DLRCVM4");
        error.setErrorMsg( "Amount is greater than limit!");
        return error;
    }

    //send to repo
    error.setErrorCode( "Yes!");
    error.setErrorMsg("success! coloian 55555");
    return error;
}
