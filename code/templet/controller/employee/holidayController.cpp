#include "holidayController.h"

QMap <QString,QVariant> holidayController::getAttributeNotDefault(holidayModel holiday)
{
    QMap <QString,QVariant> attribute;

    if(holiday.getEmpID() != "")
    {
        attribute.insert("Empid", holiday.getEmpID());
    }
    if(holiday.getAdminId() != "")
    {
        attribute.insert("Uid", holiday.getAdminId());
    }
    if(holiday.getLeaveDate() != QDate(0,0,0))
    {
        attribute.insert("SDate", holiday.getLeaveDate());
    }
    if(holiday.getBackDate() != QDate(0,0,0))
    {
        attribute.insert("EDate", holiday.getBackDate());
    }
    if(holiday.getLeaveReasons() != "")
    {
        attribute.insert("Reason", holiday.getLeaveReasons());
    }
    if(holiday.getLeaveNotes() != "")
    {
        attribute.insert("Notes", holiday.getLeaveNotes());
    }
    if(holiday.getDisc() != 0.0)
    {
        attribute.insert("Disc",holiday.getDisc() );
    }

    return attribute;
}
