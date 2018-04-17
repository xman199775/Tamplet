#ifndef DAILYLATEREPORT_H
#define DAILYLATEREPORT_H
#include <QDate>
class dailyLateReportModel
{
    QString employeeID;
    QString adminID;
    QString employeeDepID;
    QString lateTime;
    QDateTime dateOfLate;
    QString amount;
    QString reasons;

public:

    dailyLateReportModel(QString employeeID = "", QString adminID = "", QString employeeDepID = "", QString lateTime ="",
                         QDateTime dateOfLate = QDateTime(),QString amount ="" ,QString reasons = "" );
    QString getEmployeeID() const;
    void    setEmployeeID(const QString &value);
    QString getAdminID() const;
    void    setAdminID(const QString &value);
    QString     getEmployeeDep() const;
    void    setEmployeeDep(const QString &value);
    QString     getLateTime() const;
    void    setLateTime(QString value);
    QDateTime   getDateOfLate() const;
    void    setDateOfLate(const QDateTime &value);
    QString getReasons() const;
    void    setReasons(const QString &value);
    QString getAmount() const;
    void setAmount(QString value);
};

#endif // DAILYLATEREPORT_H
