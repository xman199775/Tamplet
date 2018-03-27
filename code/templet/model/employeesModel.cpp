#include "employeesModel.h"

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
