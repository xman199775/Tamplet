#include "employeedetailedreport.h"
EmployeeDetailedReport::EmployeeDetailedReport()
{
    holidays       = new QList<holidayModel>;
    lates          = new QList<dailyLateReportModel>;
    salaryModifies = new QList<modifySalaryModel>;
    efficiency     = new QList<efficiencymodel>;
}
void EmployeeDetailedReport::addHoliday(holidayModel holi)
{
    holidays->append(holi);
}
void EmployeeDetailedReport::addSalaryModification(modifySalaryModel mod)
{
    salaryModifies->append(mod);
}
void EmployeeDetailedReport::addLateReport(dailyLateReportModel late)
{
    lates->append(late);
}
void EmployeeDetailedReport::addEfficiency(efficiencymodel effic)
{
    efficiency->append(effic);
}
