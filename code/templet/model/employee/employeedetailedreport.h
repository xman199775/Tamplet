#ifndef EMPLOYEEDETAILEDREPORT_H
#define EMPLOYEEDETAILEDREPORT_H
#include <QVector>
#include <model/employee/holidayModel.h>
#include <model/employee/modifysalarymodel.h>
#include <model/employee/dailyLateReportModel.h>
class EmployeeDetailedReport
{
public:
    EmployeeDetailedReport();
    QVector<holidayModel>         *holidays;
    QVector<modifySalaryModel>    *salaryModifies;
    QVector<dailyLateReportModel> *lates;
    void addHoliday(holidayModel holi);
    void addSalaryModification(modifySalaryModel mod);
    void addLateReport(dailyLateReportModel late);
};

#endif // EMPLOYEEDETAILEDREPORT_H
