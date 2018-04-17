#include "error.h"

Error ::Error(QString errorCode, QString errorMsg)
{
    this->errorCode = errorCode;
    this->errorMsg  = errorMsg ;
}
QString Error::getErrorCode() const
{
    return errorCode;
}

void Error::setErrorCode(const QString &value)
{
    errorCode = value;
}

QString Error::getErrorMsg() const
{
    return errorMsg;
}

void Error::setErrorMsg(const QString &value)
{
    errorMsg = value;
}
