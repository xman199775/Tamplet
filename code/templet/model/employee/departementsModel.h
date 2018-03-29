#ifndef DEPARTEMENTSMODEL_H
#define DEPARTEMENTSMODEL_H
#include <QString>

class departementsModel
{
    QString depName;
    int     depID;
    public:
        QString getDepName() const;
        void setDepName(const QString &value);
        int  getDepID() const;
        void setDepID(const int &value);
};

#endif // DEPARTEMENTSMODEL_H
