#ifndef EMPLOYEESGENERALREPORT_H
#define EMPLOYEESGENERALREPORT_H
#include <QString>
#include <QList>
class EmployeesGeneralReport
{
public:
    struct SingleReport
    {
        QString empId, empName, DepName;
        double ClearSalary, TotalDiscount, TotalBonus, TotalLend, TotalHolidaysDiscount, TotalEfficiencyAmount;
        int TotalDaysLate, TotalHolidayDays;
    };
        EmployeesGeneralReport();
        void addSingleReport(SingleReport report);
private:
        QList<SingleReport>* reports;
};

#endif // EMPLOYEESGENERALREPORT_H
