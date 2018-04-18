#include "departementsController.h"

Error departementsController:: validateModel(departementsModel departementsmodel)
{
    Error error;

    if (departementsmodel.getDepID() == "")
    {
        error.setErrorCode("DCVM1");
        error.setErrorMsg("Depratement id is empty!");
        return error;
    }
    if(departementsmodel.getDepName() == "")
    {
        error.setErrorCode("DCVM2");
        error.setErrorMsg("Depratement name is empty!");
        return error;
    }

    //send to repo
    error.setErrorCode( "Yes!");
    error.setErrorMsg("success! coloian 55555");
    return error;
}
