#include "dailyLateReportModel.h"

dailyLateReportModel::dailyLateReportModel(QString employeeID , int employeeDepID , int lateTime ,
                                           QDateTime dateOfLate , QString reasons)
{
    this->employeeID     = employeeID    ;
    this->employeeDepID  = employeeDepID ;
    this->lateTime       = lateTime      ;
    this->dateOfLate     = dateOfLate    ;
    this->reasons        = reasons       ;

}

QString dailyLateReportModel::getEmployeeID() const
{
    return employeeID;
}

void dailyLateReportModel::setEmployeeID(const QString &value)
{
    employeeID = value;
}
QString dailyLateReportModel::getAdminID() const
{
    return adminID;
}

void dailyLateReportModel::setAdminID(const QString &value)
{
    adminID = value;
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

QDateTime dailyLateReportModel:: getDateOfLate() const
{
    return dateOfLate;
}
void  dailyLateReportModel ::setDateOfLate(const QDateTime &value)
{
    dateOfLate=value;
}

QString dailyLateReportModel:: getReasons() const
{
    return reasons;
}
void dailyLateReportModel::setReasons(const QString &value)
{
    reasons = value;
}
