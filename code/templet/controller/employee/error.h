#ifndef ERROR_H
#define ERROR_H
#include <QString>

class Error
{
    QString errorCode ;
    QString errorMsg  ;
public:
    Error(QString errorCode = "", QString errorMsg="" );
    QString getErrorMsg() const;
    void setErrorMsg(const QString &value);
    QString getErrorCode() const;
    void setErrorCode(const QString &value);
};

#endif // ERROR_H
