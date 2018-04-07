#include "employeeRepository.h"
#include <model/employee/employeesModel.h>
#include <system/serverconnections.h>

employeeRepository::employeeRepository()
{

}
bool employeeRepository:: addEmployee(employeesModel employee)
{
    QSqlQuery InsertQuery;

    InsertQuery.prepare("INSERT INTO Employee (Empid, Name, SSN, NickName, BirthDate, Address, PhoneNum, Email, ShiftBeg, ShiftEnd, ClearSalary, Certti) "
                  "VALUES (:Empid, :Name, :SSN, :NickName, :BirthDate, :Address, :PhoneNum, :Email, :ShiftBeg, :ShiftEnd, :ClearSalary, :Certti)");

    InsertQuery.bindValue(":Empid", employee.getEmpId());
    InsertQuery.bindValue(":Name", employee.getEmployeeName());
    InsertQuery.bindValue(":SSN", employee.getSSN());
    InsertQuery.bindValue(":NickName", employee.getPreferedName());
    InsertQuery.bindValue(":BirthDate", employee.getDateBirth());
    InsertQuery.bindValue(":Address", employee.getAddress());
    InsertQuery.bindValue(":PhoneNum", employee.getPhoneNumber());
    InsertQuery.bindValue(":Email", employee.getEmail());
    InsertQuery.bindValue(":ShiftBeg", employee.getShiftBegTime());
    InsertQuery.bindValue(":ShiftEnd", employee.getShiftEndTime());
    InsertQuery.bindValue(":ClearSalary", employee.getSalary());
    InsertQuery.bindValue(":Certti", employee.getQualification());

    return InsertQuery.exec();
}
bool employeeRepository:: deleteEmployee(int empId)
{
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Employee WHERE Empid = :Empid ");

    deleteQuery.bindValue(":Empid", empId);

    return deleteQuery.exec();
}
