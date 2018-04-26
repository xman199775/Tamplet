#include "efficiencymodel.h"

double efficiencymodel::getAmount() const
{
    return amount;
}

void efficiencymodel::setAmount(double value)
{
    amount = value;
}

QString efficiencymodel::getEmpId() const
{
    return empId;
}

void efficiencymodel::setEmpId(const QString &value)
{
    empId = value;
}

QString efficiencymodel::getAdminId() const
{
    return adminId;
}

void efficiencymodel::setAdminId(const QString &value)
{
    adminId = value;
}

QDate efficiencymodel::getDate() const
{
    return date;
}

void efficiencymodel::setDate(const QDate &value)
{
    date = value;
}

efficiencymodel::efficiencymodel(QString empId, QString adminId, double amount, QDate date)
{
    this->empId = empId  ;
    this->adminId  = adminId;
    this->amount   = amount ;
    this->date     = date   ;
}
