#include "employeesModel.h"

employeesModel::employeesModel(QString employeeName, QString preferedName, QString empId,
               QString martialStatus, QString SSN, QDate dateBirth,
               QString address, QString phoneNumber, QString homeAddress,
               QString email, QString notes, QTime shiftBegTime,
               QTime shiftEndTime, QString qualification, double salary)
{
    this->employeeName  = employeeName  ;
    this->preferedName  = preferedName  ;
    this->empId         = empId         ;
    this->martialStatus = martialStatus ;
    this->SSN           = SSN           ;
    this->dateBirth     = dateBirth     ;
    this->address       = address       ;
    this->phoneNumber   = phoneNumber   ;
    this->homeAddress   = homeAddress   ;
    this->email         = email         ;
    this->notes         = notes         ;
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

QString employeesModel::getMartialStatus() const
{
    return martialStatus;
}

void employeesModel::setMartialStatus(const QString &value)
{
    martialStatus = value;
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

QString employeesModel::getHomeAddress() const
{
    return homeAddress;
}

void employeesModel::setHomeAddress(const QString &value)
{
    homeAddress = value;
}

QString employeesModel::getEmail() const
{
    return email;
}

void employeesModel::setEmail(const QString &value)
{
    email = value;
}

QString employeesModel::getNotes() const
{
    return notes;
}

void employeesModel::setNotes(const QString &value)
{
    notes = value;
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
