#ifndef DEPARTEMENTSMODEL_H
#define DEPARTEMENTSMODEL_H
#include <QString>

class departementsModel
{
    QString depName;
    QString     depID;
    public:
        departementsModel(QString depName = "", QString depID = 0);
        QString getDepName() const;
        void setDepName(const QString &value);
        QString  getDepID() const;
        void setDepID(const QString &value);
};

#endif // DEPARTEMENTSMODEL_H
