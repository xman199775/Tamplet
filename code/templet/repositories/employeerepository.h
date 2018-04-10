#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include <model/employee/employeesModel.h>
#include <controller/employee/employeescontroller.h>
#include <model/employee/modifySalaryModel.h>
#include <controller/employee/modifysalarycontroller.h>
#include <model/employee/holidayModel.h>
#include <controller/employee/holidayController.h>
#include <system/serverconnections.h>

class employeeRepository
{
public:
    employeeRepository();
    bool addEmployee(employeesModel employee);
    bool deleteEmployee(QString empId);
    bool updateEmployee(employeesModel employee);
    bool addModification(modifySalaryModel modify);
    bool deleteModification(QString empId, QDateTime date);
    bool updateSalaryModification(modifySalaryModel modify);
    bool addHoliday(holidayModel holiday);
    bool updateHoliday(holidayModel holidayM);
    bool deleteHoliday(QString empId, QDate date);
};

#endif // EMPLOYEEREPOSITORY_H
