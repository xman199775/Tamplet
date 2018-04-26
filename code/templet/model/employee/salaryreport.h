#ifndef SALARYREPORT_H
#define SALARYREPORT_H
#include <QString>
class SalaryReport
{
public:
    double ClearSalary, PayedSalary,TotalDiscount, TotalBonus, TotalLend, TotalHolidaysDiscount;
    SalaryReport();
    void CalculatePayedSalary();
};

#endif // SALARYREPORT_H
