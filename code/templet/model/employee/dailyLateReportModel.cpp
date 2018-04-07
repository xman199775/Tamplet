#include "dailyLateReportModel.h"

dailyLateReportModel::dailyLateReportModel(QString employeeID , int employeeDepID , int lateTime ,
                                           QDate dateOfLate , QString reasons)
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

QString dailyLateReportModel:: getReasons() const
{
    return reasons;
}
void dailyLateReportModel::setReasons(const QString &value)
{
    reasons = value;
}
