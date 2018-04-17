#ifndef DAILYLATEREPORTCONTROLLER_H
#define DAILYLATEREPORTCONTROLLER_H
#include <model/employee/dailyLateReportModel.h>
#include "controller/employee/error.h"
#include <repositories/employeerepository.h>


class dailyLateReportController
{
    public:
    Error validateModel(dailyLateReportModel dailylatereportModel);


};

#endif // DAILYLATEREPORTCONTROLLER_H
