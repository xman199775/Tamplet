#include "departementsModel.h"

<<<<<<< HEAD
departementsModel::departementsModel(QString depName , int depID )
=======
departementsModel::departementsModel(QString depName , int     depID )
>>>>>>> 9a75bec966d72e025083737f4ff4e359bf615871
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

