#include "holidayModel.h"

holidayModel::holidayModel(QString empID, QString adminID, QDate leaveDate, QDate backDate,
                           QString leaveReasons, QString leaveNotes, double disc)
{
    this->empID        = empID        ;
    this->adminID      = adminID      ;
    this->leaveDate    = leaveDate    ;
    this->backDate     = backDate     ;
    this->leaveReasons = leaveReasons ;
    this->leaveNotes   = leaveNotes   ;
    this->disc         = disc         ;

}

QString holidayModel::getAdminID() const
{
    return adminID;
}

void holidayModel::setAdminID(const QString &value)
{
    adminID = value;
}

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

double holidayModel::getDisc()
{
    return disc;
}
void holidayModel ::setDisc(double value)
{
    disc = value;
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


