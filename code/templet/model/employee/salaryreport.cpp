#include "salaryreport.h"

SalaryReport::SalaryReport()
{
}
void SalaryReport::CalculatePayedSalary()
{
    PayedSalary = ClearSalary - (TotalDiscount + TotalHolidaysDiscount  + TotalLend) + (TotalBonus);
}
