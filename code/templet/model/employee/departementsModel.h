#ifndef DEPARTEMENTSMODEL_H
#define DEPARTEMENTSMODEL_H
#include <QString>

class departementsModel
{
    QString depName;
    int     depID;
    public:
        departementsModel(QString depName = "", int     depID = 0);
        QString getDepName() const;
        void setDepName(const QString &value);
        int  getDepID() const;
        void setDepID(const int &value);
};

#endif // DEPARTEMENTSMODEL_H
