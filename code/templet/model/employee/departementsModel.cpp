#include "departementsModel.h"

departementsModel::departementsModel(QString depName , int     depID )
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

int departementsModel::getDepID() const
{
    return depID;
}

void departementsModel::setDepID(const int &value)
{
    depID = value;
}

