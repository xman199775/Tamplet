#include "holidayModel.h"

QString holidayModel::getEmpID() const
{
    return empID;
}

void holidayModel::setEmpID(const QString &value)
{
    empID = value;
}

QDate holidayModel::getLeaveDate() const
{
    return leaveDate;
}

void holidayModel::setLeaveDate(const QDate &value)
{
    leaveDate = value;
}

QDate holidayModel::getBackDate() const
{
    return backDate;
}

void holidayModel::setBackDate(const QDate &value)
{
    backDate = value;
}

QString holidayModel::getLeaveReasons() const
{
    return leaveReasons;
}

void holidayModel::setLeaveReasons(const QString &value)
{
    leaveReasons = value;
}

QString holidayModel::getLeaveNotes() const
{
    return leaveNotes;
}

void holidayModel::setLeaveNotes(const QString &value)
{
    leaveNotes = value;
}


