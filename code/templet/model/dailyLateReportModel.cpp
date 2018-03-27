#include "dailyLateReportModel.h"

QString dailyLateReportModel::getEmployeeID() const
{
    return employeeID;
}

void dailyLateReportModel::setEmployeeID(const QString &value)
{
    employeeID = value;
}

int dailyLateReportModel::getEmployeeDep() const
{
    return employeeDepID;
}

void dailyLateReportModel::setEmployeeDep(const int &value)
{
    employeeDepID = value;
}

int dailyLateReportModel::getLateTime() const
{
    return lateTime;
}

void dailyLateReportModel::setLateTime(int value)
{
    lateTime = value;
}

QDate dailyLateReportModel:: getDateOfLate() const
{
    return dateOfLate;
}
void  dailyLateReportModel ::setDateOfLate(const QDate &value)
{
    dateOfLate=value;
}
