#include "employeesModel.h"

employeesModel::employeesModel(QString empId, QString employeeName, QString SSN,
                               QString phoneNumber, QString address,
                               QTime shiftBegTime, QTime shiftEndTime, QDate dateBirth,
                               QString email, QString qualification, double salary, QString preferedName)
{
    this->employeeName  = employeeName  ;
    this->preferedName  = preferedName  ;
    this->empId         = empId         ;
    this->SSN           = SSN           ;
    this->dateBirth     = dateBirth     ;
    this->address       = address       ;
    this->phoneNumber   = phoneNumber   ;
    this->email         = email         ;
    this->shiftBegTime  = shiftBegTime  ;
    this->shiftEndTime  = shiftEndTime  ;
    this->qualification = qualification ;
    this->salary        = salary        ;
}

QString employeesModel::getEmployeeName() const
{
    return employeeName;
}

void employeesModel::setEmployeeName(const QString &value)
{
    employeeName = value;
}

QString employeesModel::getPreferedName() const
{
    return preferedName;
}

void employeesModel::setPreferedName(const QString &value)
{
    preferedName = value;
}

QString employeesModel::getEmpId() const
{
    return empId;
}

void employeesModel::setEmpId(QString value)
{
    empId = value;
}

QDate employeesModel::getDateBirth() const
{
    return dateBirth;
}

void employeesModel::setDateBirth(const QDate &value)
{
    dateBirth = value;
}

QString employeesModel::getAddress() const
{
    return address;
}

void employeesModel::setAddress(const QString &value)
{
    address = value;
}

QString employeesModel::getPhoneNumber() const
{
    return phoneNumber;
}

void employeesModel::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
}

QString employeesModel::getEmail() const
{
    return email;
}

void employeesModel::setEmail(const QString &value)
{
    email = value;
}

QTime employeesModel::getShiftBegTime() const
{
    return shiftBegTime;
}

void employeesModel::setShiftBegTime(const QTime &value)
{
    shiftBegTime = value;
}

QTime employeesModel::getShiftEndTime() const
{
    return shiftEndTime;
}

void employeesModel::setShiftEndTime(const QTime &value)
{
    shiftEndTime = value;
}

double employeesModel::getSalary() const
{
    return salary;
}

void employeesModel::setSalary(const double &value)
{
    salary = value;
}

QString employeesModel::getQualification() const
{
    return qualification;
}

void employeesModel::setQualification(const QString &value)
{
    qualification = value;
}
QString employeesModel::getSSN() const
{
    return SSN;
}
void employeesModel::setSSN(const QString &value)
{
    SSN = value;
}
