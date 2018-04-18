#include "modifysalarymodel.h"

modifySalaryModel::modifySalaryModel(QString employeeID, QString adminID, QDateTime dateOfModify,
                                     char type, double amount, QString reason)
{
    this->employeeID    = employeeID   ;
    this->adminID       = adminID      ;
    this->dateOfModify  = dateOfModify ;
    this->amount        = amount       ;
    this->reason        = reason       ;
    this->type          = type         ;
}

QString modifySalaryModel::getReason() const
{
    return reason;
}

void modifySalaryModel::setReason(const QString &value)
{
    reason = value;
}

double modifySalaryModel::getAmount() const
{
    return amount;
}

void modifySalaryModel::setAmount(double value)
{
    amount = value;
}

QDateTime modifySalaryModel::getDateOfModify() const
{
    return dateOfModify;
}

void modifySalaryModel::setDateOfModify(const QDateTime &value)
{
    dateOfModify = value;
}

QString modifySalaryModel::getAdminID() const
{
    return adminID;
}

void modifySalaryModel::setAdminID(const QString &value)
{
    adminID = value;
}

QString modifySalaryModel::getEmployeeID() const
{
    return employeeID;
}

void modifySalaryModel::setEmployeeID(const QString &value)
{
    employeeID = value;
}

char modifySalaryModel::getType() const
{
    return type;
}

void modifySalaryModel::setType(char value)
{
    type = value;
}
