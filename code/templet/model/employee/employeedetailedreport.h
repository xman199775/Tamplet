#ifndef EMPLOYEEDETAILEDREPORT_H
#define EMPLOYEEDETAILEDREPORT_H
#include <QList>
#include <model/employee/holidayModel.h>
#include <model/employee/modifysalarymodel.h>
#include <model/employee/dailyLateReportModel.h>
#include <model/employee/efficiencymodel.h>
class EmployeeDetailedReport
{
public:
    EmployeeDetailedReport();
    QList<holidayModel>         *holidays;
    QList<modifySalaryModel>    *salaryModifies;
    QList<dailyLateReportModel> *lates;
    QList<efficiencymodel>      *efficiency;
    void addHoliday(holidayModel holi);
    void addSalaryModification(modifySalaryModel mod);
    void addLateReport(dailyLateReportModel late);
    void addEfficiency(efficiencymodel effic);
};

#endif // EMPLOYEEDETAILEDREPORT_H
