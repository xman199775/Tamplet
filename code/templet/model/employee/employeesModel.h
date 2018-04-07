#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <QDate>

class employeesModel
{
    QString empId;
    QString employeeName;
    QString SSN;
    QString phoneNumber;
    QString address;
    QTime   shiftBegTime;
    QTime   shiftEndTime;
    QDate   dateBirth;
    QString email;
    QString qualification;
    double  salary;
    QString preferedName;

public:
    employeesModel(QString empId = "" ,QString employeeName = "", QString SSN = "",
                   QString phoneNumber = "", QString address = "", QTime shiftBegTime = QTime(0,0,0,0),
                   QTime shiftEndTime = QTime(0,0,0,0), QDate dateBirth= QDate(0,0,0),
                   QString email = "", QString qualification = "", double salary = 0.0,  QString preferedName = "" );

    QString getEmployeeName() const;
    void    setEmployeeName(const QString &value);
    QString getPreferedName() const;
    void    setPreferedName(const QString &value);
    QString getEmpId() const;
    void    setEmpId(QString value);
    QString getSSN() const;
    void    setSSN(const QString &value);
    QDate   getDateBirth() const;
    void    setDateBirth(const QDate &value);
    QString getAddress() const;
    void    setAddress(const QString &value);
    QString getPhoneNumber() const;
    void    setPhoneNumber(const QString &value);
    QString getEmail() const;
    void    setEmail(const QString &value);
    QTime   getShiftBegTime() const;
    void    setShiftBegTime(const QTime &value);
    QTime   getShiftEndTime() const;
    void    setShiftEndTime(const QTime &value);
    double  getSalary() const;
    void    setSalary(const double &value);
    QString getQualification() const;
    void    setQualification(const QString &value);

};

#endif // EMPLOYEES_H
