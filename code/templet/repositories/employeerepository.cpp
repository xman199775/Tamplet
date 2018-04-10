#include "employeeRepository.h"

employeeRepository::employeeRepository()
{

}
bool employeeRepository:: addEmployee(employeesModel employee)
{

    QSqlQuery InsertQuery(serverConnections::getInstance()->getserverConnections("general"));

    InsertQuery.prepare("INSERT INTO `Employee` ( `Empid`, `Name`, `SSN`, `NickName`, `BirthDate`, `Address`, `PhoneNum`, `Email`, `ShiftBeg`, `ShiftEnd`, `ClearSalary`, `Certti`)"
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
    deleteQuery.prepare("DELETE FROM `Employee` WHERE `Empid` = :Empid ");

    deleteQuery.bindValue(":Empid", empId);

    return deleteQuery.exec();
}
bool employeeRepository::updateEmployee(employeesModel employee)
{
    employeesController employeeController;
    QMap<QString,QVariant> Attribute=employeeController.getAttributeNotDefault(employee);
    QSqlQuery updateQuery(serverConnections::getInstance()->getserverConnections("general"));
    QString query="UPDATE `employee` SET ";
    for(QString feildName:Attribute.keys())
    {
        query+="`";
        query+=feildName;
        query+="` = :";
        query+=feildName;
        query+=" ";
    }
    query+=" WHERE `Empid`= :Empid ; ";
    updateQuery.prepare(query);
    for(QString feildName:Attribute.keys())
    {
        updateQuery.bindValue(":"+feildName,Attribute.value(feildName));
    }
    updateQuery.bindValue(":Empid",employee.getEmpId());
    return updateQuery.exec();


}
bool employeeRepository::addModification(modifySalaryModel modify)
{
    QSqlQuery InsertQuery(serverConnections::getInstance()->getserverConnections("general"));

    InsertQuery.prepare("INSERT INTO `ModifySalary` (`Empid`, `Uid`, `Date`, `type`, `amount`, `Reasons`, `NewSalary`) "
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

    deleteQuery.prepare("DELETE FROM `ModifySalary` WHERE `Empid` = :Empid AND `Date` = :Date ");

    deleteQuery.bindValue(":Empid", empId);
    deleteQuery.bindValue(":Date", date);

    return deleteQuery.exec();

}
bool employeeRepository:: updateSalaryModification(modifySalaryModel modify)
{
    modifysalarycontroller mod ;
    QMap<QString,QVariant> attribute = mod.getAttributeNotDefault(modify);

    QSqlQuery updateQuery(serverConnections::getInstance()->getserverConnections("general"));

    QString query="UPDATE `modifySalary` SET ";
    for(QString feildName:attribute.keys())
    {
        query+="`";
        query+=feildName;
        query+="` = :";
        query+=feildName;
        query+=" ";
    }

    query+=" WHERE `Empid`= :Empid AND `Date` = :Date ; ";
    updateQuery.prepare(query);

    for(QString feildName:attribute.keys())
    {
        updateQuery.bindValue(":"+feildName,attribute.value(feildName));
    }
    updateQuery.bindValue(":Empid",modify.getEmployeeID());
    return updateQuery.exec();

}

bool employeeRepository::addHoliday(holidayModel holiday)
{
    QSqlQuery InsertQuery(serverConnections::getInstance()->getserverConnections("general"));

    InsertQuery.prepare("INSERT INTO `Vacation` (`Empid` ,`Uid` ,`SDate` ,`EDate` ,`Reason` ,`Notes` ,`Disc` )"
                        "VALUES (:Empid, :Uid, :SDate, :EDate, :Reason, :Notes, :Disc) " );

    InsertQuery.bindValue(":Empid", holiday.getEmpID())         ;
    InsertQuery.bindValue(":Uid", holiday.getAdminId())         ;
    InsertQuery.bindValue(":SDate", holiday.getLeaveDate())     ;
    InsertQuery.bindValue(":EDate", holiday.getBackDate())      ;
    InsertQuery.bindValue(":Reason", holiday.getLeaveReasons()) ;
    InsertQuery.bindValue(":Notes", holiday.getLeaveNotes())    ;
    InsertQuery.bindValue(":Disc", holiday.getDisc())           ;

    return InsertQuery.exec();
}
bool employeeRepository::updateHoliday(holidayModel holidayM)
{
    holidayController holiday;
    QMap<QString,QVariant> attribute=holiday.getAttributeNotDefault(holidayM);
    QSqlQuery updateQuery(serverConnections::getInstance()->getserverConnections("general"));
    QString query="UPDATE `Vacation` SET ";
    for(QString feildName:attribute.keys())
    {
        query+="`";
        query+=feildName;
        query+="` = :";
        query+=feildName;
        query+=" ";
    }
    query+=" WHERE `Empid`= :Empid AND `SDate` = :SDate ; ";
    updateQuery.prepare(query);
    for(QString feildName:attribute.keys())
    {
        updateQuery.bindValue(":"+feildName,attribute.value(feildName));
    }
    updateQuery.bindValue(":Empid",holidayM.getEmpID());
    return updateQuery.exec();

}

bool deleteHoliday(QString empId, QDate date)
{
    QSqlQuery deleteQuery(serverConnections::getInstance()->getserverConnections("general"));

    deleteQuery.prepare("DELETE FROM `Vacation` WHERE `Empid` = :Empid AND `SDate` = :SDate ");

    deleteQuery.bindValue(":Empid", empId);
    deleteQuery.bindValue(":SDate", date);

    return deleteQuery.exec();


}
