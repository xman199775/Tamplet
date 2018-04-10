#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include <model/employee/employeesModel.h>
#include <controller/employee/employeescontroller.h>
#include <model/employee/modifysalarymodel.h>
#include <controller/employee/modifysalarycontroller.h>
#include <system/serverconnections.h>
#include <QVector>
#include <model/employee/employeedetailedreport.h>
#include <model/employee/employeesgeneralreport.h>
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
    EmployeeDetailedReport* generateDetailedReport(QString empId, QDateTime range0, QDateTime range1);
    EmployeesGeneralReport* generateGeneralReport(QDate range0, QDate range1);
};

#endif // EMPLOYEEREPOSITORY_H
