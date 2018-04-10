#include "employeesgeneralreport.h"

EmployeesGeneralReport::EmployeesGeneralReport()
{
    reports = new QVector<SingleReport>;
}
void EmployeesGeneralReport::addSingleReport(SingleReport report)
{
    reports->push_back(report);
}
