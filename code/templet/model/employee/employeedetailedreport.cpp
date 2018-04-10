#include "employeedetailedreport.h"

EmployeeDetailedReport::EmployeeDetailedReport()
{
    holidays       = new QVector<holidayModel>;
    lates          = new QVector<dailyLateReportModel>;
    salaryModifies = new QVector<modifySalaryModel>;
}
void EmployeeDetailedReport::addHoliday(holidayModel holi)
{
    holidays->push_back(holi);
}
void EmployeeDetailedReport::addSalaryModification(modifySalaryModel mod)
{
    salaryModifies->push_back(mod);
}
void EmployeeDetailedReport::addLateReport(dailyLateReportModel late)
{
    lates->push_back(late);
}
