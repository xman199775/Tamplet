#ifndef EFFICIENCYMODEL_H
#define EFFICIENCYMODEL_H
#include <QString>
#include <QDate>


class efficiencymodel
{
    QString empId;
    QString adminId;
    double amount;
    QDate date;
public:
    efficiencymodel(QString empId ="", QString adminId ="", double amount =0.0, QDate date = QDate(0,0,0));
    double getAmount() const;
    void setAmount(double value);
    QString getEmpId() const;
    void setEmpId(const QString &value);
    QString getAdminId() const;
    void setAdminId(const QString &value);
    QDate getDate() const;
    void setDate(const QDate &value);
};

#endif // EFFICIENCYMODEL_H
