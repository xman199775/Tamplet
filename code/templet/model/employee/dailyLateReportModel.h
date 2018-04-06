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
<<<<<<< HEAD
    dailyLateReportModel(QString employeeID = "",int employeeDepID = 0, int lateTime = 0,
                         QDate dateOfLate = QDate(0,0,0) );
=======
    dailyLateReportModel(QString employeeID = "",int employeeDepID = 0, int lateTime = 0, QDate dateOfLate = QDate(0,0,0) );
>>>>>>> 9a75bec966d72e025083737f4ff4e359bf615871
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
