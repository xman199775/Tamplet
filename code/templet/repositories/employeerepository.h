#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include <model\employee\employeesModel.h>

class employeeRepository
{
public:
    employeeRepository();
    bool addEmployee(employeesModel employee);
    bool deleteEmployee(int empId);
};

#endif // EMPLOYEEREPOSITORY_H
