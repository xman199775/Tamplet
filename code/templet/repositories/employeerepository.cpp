#include "employeeRepository.h"
#include <model\employee\employeesModel.h>
#include <system\serverconnections.h>
#include <model\employee\modifySalaryModel.h>

employeeRepository::employeeRepository()
{

}
bool employeeRepository:: addEmployee(employeesModel employee)
{

    QSqlQuery InsertQuery(serverConnections::getInstance()->getserverConnections("general"));

    InsertQuery.prepare("INSERT INTO Employee ( Empid,  Name,  SSN,  NickName,  BirthDate,  Address,  PhoneNum, Email,  ShiftBeg,  ShiftEnd,  ClearSalary,  Certti)"
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
bool employeeRepository:: deleteEmployee(QString empId)
{
    QSqlQuery deleteQuery(serverConnections::getInstance()->getserverConnections("general"));
    deleteQuery.prepare("DELETE FROM Employee WHERE Empid = :Empid ");

    deleteQuery.bindValue(":Empid", empId);

    return deleteQuery.exec();
}

bool employeeRepository::addModification(modifySalaryModel modify)
{
    QSqlQuery InsertQuery(serverConnections::getInstance()->getserverConnections("general"));

    InsertQuery.prepare("INSERT INTO ModifySalary (Empid, Uid, Date, type, amount, Reasons, NewSalary) "
                        "Values (:Empid, :Uid, :Date, :type, :amount, :Reasons, :NewSalary)" );

    InsertQuery.bindValue(":Empid",modify.getEmployeeID() );
    InsertQuery.bindValue(":Uid", modify.getAdminID());
    InsertQuery.bindValue(":Date", modify.getDateOfModify() );
    InsertQuery.bindValue(":type", modify.getType());
    InsertQuery.bindValue(":amount", modify.getAmount());
    InsertQuery.bindValue(":Reasons", modify.getReason());
    InsertQuery.bindValue(":NewSalary", modify.getNewSalary());

    return InsertQuery.exec();
}
bool employeeRepository:: deleteModification(QString empId, QDateTime date)
{
    QSqlQuery deleteQuery(serverConnections::getInstance()->getserverConnections("general"));

    deleteQuery.prepare("DELETE FROM ModifySalary WHERE Empid = :Empid AND Date = :Date ");

    deleteQuery.bindValue(":Empid", empId);
    deleteQuery.bindValue(":Date", date);

    return deleteQuery.exec();

}
