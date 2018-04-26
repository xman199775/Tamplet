#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include <model/employee/employeesModel.h>
#include <controller/employee/employeescontroller.h>
#include <model/employee/modifysalarymodel.h>
#include <controller/employee/modifysalarycontroller.h>
#include <model/employee/holidayModel.h>
#include <controller/employee/holidayController.h>
#include <system/serverconnections.h>
#include <QVector>
#include <model/employee/employeedetailedreport.h>
#include <model/employee/employeesgeneralreport.h>
#include <model/employee/efficiencymodel.h>
#include <controller/employee/efficiencycontroller.h>

class employeeRepository
{
public:
    employeeRepository();
    bool addEmployee(employeesModel employee);
    bool deleteEmployee(QString empId);
    bool updateEmployee(employeesModel employee);
    bool addModification(modifySalaryModel modify);
    bool deleteModification(QString empId, QDateTime date  );
    bool updateSalaryModification(modifySalaryModel modify );
    bool addHoliday(holidayModel holiday);
    bool updateHoliday(holidayModel holidayM);
    bool deleteHoliday(QString empId, QDate date);
    EmployeeDetailedReport* generateDetailedReport(QString empId, QDateTime range0, QDateTime range1);
    EmployeesGeneralReport* generateGeneralReport(QDate range0, QDate range1);
    bool addEfficiency(efficiencymodel efficiency);
    bool deleteEfficiency(QString empId);
    bool updateEfficiency(efficiencymodel efficiency);
};

#endif // EMPLOYEEREPOSITORY_H
