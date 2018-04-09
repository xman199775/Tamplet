#ifndef DAILYLATEREPORT_H
#define DAILYLATEREPORT_H
#include <QDate>
class dailyLateReportModel
{
    QString employeeID;
    QString adminID;
    int employeeDepID;
    int lateTime;
    QDateTime dateOfLate;
    QString reasons;

public:

    dailyLateReportModel(QString employeeID = "",int employeeDepID = 0, int lateTime = 0,
                         QDateTime dateOfLate = QDateTime(), QString reasons = "" );
    QString getEmployeeID() const;
    void    setEmployeeID(const QString &value);
    QString getAdminID() const;
    void    setAdminID(const QString &value);
    int     getEmployeeDep() const;
    void    setEmployeeDep(const int &value);
    int     getLateTime() const;
    void    setLateTime(int value);
    QDateTime   getDateOfLate() const;
    void    setDateOfLate(const QDateTime &value);
    QString getReasons() const;
    void    setReasons(const QString &value);

};

#endif // DAILYLATEREPORT_H
