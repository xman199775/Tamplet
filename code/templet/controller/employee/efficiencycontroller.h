#ifndef EFFICIENCYCONTROLLER_H
#define EFFICIENCYCONTROLLER_H
#include <QMap>
#include <QVariant>
#include <model/employee/efficiencymodel.h>
#include <controller/employee/error.h>
#include <repositories/employeerepository.h>

class efficiencycontroller
{
public:
    efficiencycontroller();

    Error validateModel(efficiencymodel effmodel);
    QMap <QString,QVariant> getAttributeNotDefault(efficiencymodel efficiency);
};

#endif // EFFICIENCYCONTROLLER_H
