#include "departementsModel.h"


departementsModel::departementsModel(QString depName , QString  depID )

{
    this->depName = depName ;
    this->depID   = depID   ;

}

QString departementsModel::getDepName() const
{
    return depName;
}

void departementsModel::setDepName(const QString &value)
{
    depName = value;
}

QString departementsModel::getDepID() const
{
    return depID;
}

void departementsModel::setDepID(const QString &value)
{
    depID = value;
}

