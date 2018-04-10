#ifndef EMPLOYEESGENERALREPORT_H
#define EMPLOYEESGENERALREPORT_H
#include <QString>
#include <QVector>
class EmployeesGeneralReport
{
public:
    struct SingleReport
    {
        QString empId, empName, DepName;
        double ClearSalary, TotalDiscount, TotalBonus, TotalLend, TotalHolidaysDiscount;
        int TotalDaysLate, TotalHolidayDays;
    };
        EmployeesGeneralReport();
        void addSingleReport(SingleReport report);
private:
        QVector<SingleReport>* reports;
};

#endif // EMPLOYEESGENERALREPORT_H
