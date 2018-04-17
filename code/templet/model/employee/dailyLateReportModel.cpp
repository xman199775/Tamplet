#include "dailyLateReportModel.h"

dailyLateReportModel::dailyLateReportModel(QString employeeID, QString adminID, QString employeeDepID , QString lateTime,
                                           QDateTime dateOfLate, QString amount, QString reasons)
{
    this->employeeID     = employeeID    ;
    this->adminID        = adminID       ;
    this->employeeDepID  = employeeDepID ;
    this->lateTime       = lateTime      ;
    this->dateOfLate     = dateOfLate    ;
    this->amount         = amount        ;
    this->reasons        = reasons       ;

}

QString dailyLateReportModel::getAmount() const
{
    return amount;
}

void dailyLateReportModel::setAmount(QString value)
{
    amount = value;
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

QString dailyLateReportModel::getEmployeeDep() const
{
    return employeeDepID;
}

void dailyLateReportModel::setEmployeeDep(const QString &value)
{
    employeeDepID = value;
}

QString dailyLateReportModel::getLateTime() const
{
    return lateTime;
}

void dailyLateReportModel::setLateTime(QString value)
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
