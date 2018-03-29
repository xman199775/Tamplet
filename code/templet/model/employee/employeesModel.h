#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <QDate>

class employeesModel
{
    QString employeeName;
    QString preferedName;
    QString empId;
    QString martialStatus;
    QChar *SSN[14];
    QDate dateBirth;
    QString address;
    QString phoneNumber;
    QString homeAddress;
    QString email;
    QString notes;
    QTime shiftBegTime;
    QTime shiftEndTime;
    QString qualification;
    double salary;

    public:
        employeesModel(QString employeeName = "", QString preferedName = "", QString empId = "",
                       QString martialStatus = "", QChar *SSN[14] = NULL, QDate dateBirth = NULL,
                       QString address = "", QString phoneNumber = "", QString homeAddress = "",
                       QString email = "", QString notes = "", QTime shiftBegTime = NULL,
                       QTime shiftEndTime = NULL, QString qualification = "", double salary = 0.0 );
        QString getEmployeeName() const;
        void    setEmployeeName(const QString &value);
        QString getPreferedName() const;
        void    setPreferedName(const QString &value);
        QString getEmpId() const;
        void    setEmpId(QString value);
        QString getMartialStatus() const;
        void    setMartialStatus(const QString &value);
        QDate   getDateBirth() const;
        void    setDateBirth(const QDate &value);
        QString getAddress() const;
        void    setAddress(const QString &value);
        QString getPhoneNumber() const;
        void    setPhoneNumber(const QString &value);
        QString getHomeAddress() const;
        void    setHomeAddress(const QString &value);
        QString getEmail() const;
        void    setEmail(const QString &value);
        QString getNotes() const;
        void    setNotes(const QString &value);
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
