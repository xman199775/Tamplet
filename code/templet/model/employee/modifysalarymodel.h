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
    char      type        ; // d for dis, z for add and s for boorow . default is dis
    double    newSalary   ;
public:
    modifySalaryModel(QString employeeID = "", QString adminID = "", QDateTime dateOfModify=QDateTime(),
                      double amount = 0.0, QString reason = "", double newSalary = 0.0, char type='d');
    bool getType() const;
    void setType(char value);
    double getNewSalary() const;
    void setNewSalary(double value);
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
