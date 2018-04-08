#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include <model\employee\employeesModel.h>
#include <model\employee/modifysalarymodel.h>

class employeeRepository
{
public:
    employeeRepository();
    bool addEmployee(employeesModel employee);
    bool deleteEmployee(QString empId);
    bool addModification(modifySalaryModel modify);
    bool deleteModification(QString empId, QDateTime date);
};

#endif // EMPLOYEEREPOSITORY_H
