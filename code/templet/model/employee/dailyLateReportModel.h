#ifndef DAILYLATEREPORT_H
#define DAILYLATEREPORT_H
#include <QDate>
class dailyLateReportModel
{
    QString employeeID;
    int employeeDepID;
    int lateTime;
    QDate dateOfLate;
public:
    QString getEmployeeID() const;
    void    setEmployeeID(const QString &value);
    int     getEmployeeDep() const;
    void    setEmployeeDep(const int &value);
    int     getLateTime() const;
    void    setLateTime(int value);
    QDate   getDateOfLate() const;
    void    setDateOfLate(const QDate &value);

};

#endif // DAILYLATEREPORT_H
