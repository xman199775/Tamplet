#ifndef HOLIDAYMODEL_H
#define HOLIDAYMODEL_H
#include <QDate>

class holidayModel
{
    QString empID;
    QString adminID;
    QDate   leaveDate;
    QDate   backDate;
    QString leaveReasons;
    QString leaveNotes;
    double  disc;

    public:
        holidayModel(QString empID = "",QString adminId = "" ,QDate leaveDate=QDate(0,0,0), QDate backDate=QDate(0,0,0),
                     QString leaveReasons = "", QString leaveNotes = "", double  disc = 0.0 );
        QString getEmpID() const;
        void    setEmpID(const QString &value);
        QString getAdminID() const;
        void    setAdminID(const QString &value);
        QDate   getLeaveDate() const;
        void    setLeaveDate(const QDate &value);
        QDate   getBackDate() const;
        void    setBackDate(const QDate &value);
        double  getDisc();
        void    setDisc(double value);
        QString getLeaveReasons() const;
        void    setLeaveReasons(const QString &value);
        QString getLeaveNotes() const;
        void    setLeaveNotes(const QString &value);
        QString getAdminId() const;
        void setAdminId(const QString &value);

};

#endif // HOLIDAYMODEL_H
