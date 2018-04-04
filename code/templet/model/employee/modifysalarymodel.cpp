#include "modifysalarymodel.h"

modifySalaryModel::modifySalaryModel(QString employeeID, QString adminID, QDateTime dateOfModify,
                                     double amount, QString reason, QString note, bool type)
{
    this->employeeID    = employeeID   ;
    this->adminID       = adminID      ;
    this->dateOfModify  = dateOfModify ;
    this->amount        = amount       ;
    this->reason        = reason       ;
    this->note          = note         ;
    this->type          = type         ;
}

QString modifySalaryModel::getNote() const
{
    return note;
}

void modifySalaryModel::setNote(const QString &value)
{
    note = value;
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

bool modifySalaryModel::getType() const
{
    return type;
}

void modifySalaryModel::setType(bool value)
{
    type = value;
}
