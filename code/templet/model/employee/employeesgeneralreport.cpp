#include "employeesgeneralreport.h"

EmployeesGeneralReport::EmployeesGeneralReport()
{
    reports = new QList<SingleReport>;
}
void EmployeesGeneralReport::addSingleReport(SingleReport report)
{
    reports->push_back(report);
}
