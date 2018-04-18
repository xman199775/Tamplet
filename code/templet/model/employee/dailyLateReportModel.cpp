#include "dailyLateReportModel.h"


dailyLateReportModel::dailyLateReportModel(QString employeeID, QString adminID,
                                           QDateTime dateOfLate, int amount, QString reasons, int limit)
{
    this->employeeID     = employeeID    ;
    this->adminID        = adminID       ;
    this->dateOfLate     = dateOfLate    ;
    this->amount         = amount        ;
    this->reasons        = reasons       ;
    this->limit          = limit         ;

}

int dailyLateReportModel::getAmount() const
{
    return amount;
}

void dailyLateReportModel::setAmount(int value)
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

int dailyLateReportModel::getLimit() const
{
    return limit;
}

void dailyLateReportModel::setLimit(int value)
{
    limit = value;
}
