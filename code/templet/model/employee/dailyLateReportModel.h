#ifndef DAILYLATEREPORT_H
#define DAILYLATEREPORT_H
#include <QDate>
class dailyLateReportModel
{
    QString employeeID  ;
    QString adminID     ;
    QDateTime dateOfLate;
    int amount          ;
    QString reasons     ;
    int limit           ;

public:

    dailyLateReportModel(QString employeeID = "", QString adminID = "",QDateTime dateOfLate = QDateTime(),
                         int amount =0, QString reasons = "", int limit = 9 );

    QString getEmployeeID() const;
    void    setEmployeeID(const QString &value);
    QString getAdminID() const;
    void    setAdminID(const QString &value);
    QDateTime   getDateOfLate() const;
    void    setDateOfLate(const QDateTime &value);
    QString getReasons() const;
    void    setReasons(const QString &value);
    int getAmount() const;
    void setAmount(int value);
    int getLimit() const;
    void setLimit(int value);
};

#endif // DAILYLATEREPORT_H
