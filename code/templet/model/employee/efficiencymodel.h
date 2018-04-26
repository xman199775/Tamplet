#ifndef EFFICIENCYMODEL_H
#define EFFICIENCYMODEL_H
#include <QString>
#include <QDate>


class efficiencymodel
{
    QString empId;
    QString adminId;
    double amount;
    QDateTime date;
public:
    efficiencymodel(QString empId ="", QString adminId ="", double amount =0.0, QDateTime date = QDateTime(QDate(0,0,0)));
    double getAmount() const;
    void setAmount(double value);
    QString getEmpId() const;
    void setEmpId(const QString &value);
    QString getAdminId() const;
    void setAdminId(const QString &value);
    QDateTime getDate() const;
    void setDate(const QDateTime &value);
};

#endif // EFFICIENCYMODEL_H
