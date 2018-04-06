#ifndef MODIFYSALARYMODEL_H
#define MODIFYSALARYMODEL_H
#include <QDateTime>

class modifySalaryModel
{
private:
    QString   employeeID  ;
    QString   adminID     ;
    QDateTime dateOfModify;
    double    amount      ;
    QString   reason      ;
    QString   note        ;
    bool       type       ; // true  for increasing , false for decreasing
public:
<<<<<<< HEAD
    modifySalaryModel(QString employeeID = "", QString adminID = "", QDateTime dateOfModify(0,0,0,0),
                      double amount = 0.0, QString reason = "", QString note = "", bool type);
=======
    modifySalaryModel(QString employeeID = "", QString adminID = "", QDateTime dateOfModify = NULL,
                      double amount = 0.0, QString reason = "", QString note = "", bool type=false);
>>>>>>> 9a75bec966d72e025083737f4ff4e359bf615871
    bool getType() const;
    void setType(bool value);
    QString getNote() const;
    void setNote(const QString &value);
    QString getReason() const;
    void setReason(const QString &value);
    double getAmount() const;
    void setAmount(double value);
    QDateTime getDateOfModify() const;
    void setDateOfModify(const QDateTime &value);
    QString getAdminID() const;
    void setAdminID(const QString &value);
    QString getEmployeeID() const;
    void setEmployeeID(const QString &value);
};

#endif // MODIFYSALARYMODEL_H
