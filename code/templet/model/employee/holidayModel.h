#ifndef HOLIDAYMODEL_H
#define HOLIDAYMODEL_H
#include <QDate>

class holidayModel
{
    QString empID;
    QDate   leaveDate;
    QDate   backDate;
    QString leaveReasons;
    QString leaveNotes;

    public:
        holidayModel(QString empID = "", QDate leaveDate(0,0,0), QDate backDate(0,0,0),
                     QString leaveReasons = "", QString leaveNotes = "" );
        QString getEmpID() const;
        void    setEmpID(const QString &value);
        QDate   getLeaveDate() const;
        void    setLeaveDate(const QDate &value);
        QDate   getBackDate() const;
        void    setBackDate(const QDate &value);
        QString getLeaveReasons() const;
        void    setLeaveReasons(const QString &value);
        QString getLeaveNotes() const;
        void    setLeaveNotes(const QString &value);
};

#endif // HOLIDAYMODEL_H
