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
    bool      type        ; // true  for increasing , false for decreasing
    double    newSalary   ;
public:
    modifySalaryModel(QString employeeID = "", QString adminID = "", QDateTime dateOfModify=QDateTime(),
                      double amount = 0.0, QString reason = "", double newSalary = 0.0, bool type=false);
    bool getType() const;
    void setType(bool value);
    double getNewSalary() const;
    void setNewSalary(double &value);
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
