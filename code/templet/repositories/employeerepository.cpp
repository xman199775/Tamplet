#include "employeeRepository.h"

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
bool employeeRepository::deleteEmployee(QString empId)
{
    QSqlQuery deleteQuery(serverConnections::getInstance()->getserverConnections("general"));
    deleteQuery.prepare("DELETE FROM Employee WHERE Empid = :Empid ");

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
bool employeeRepository:: updateSalaryModification(modifySalaryModel modify)
{
    modifysalarycontroller modifyController ;
    QMap<QString,QVariant> attribute = modifyController.getAttributeNotDefault(modify);

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
    updateQuery.bindValue(":Date",modify.getDateOfModify());

    return updateQuery.exec();

}
EmployeeDetailedReport* employeeRepository::generateDetailedReport(QString empId, QDateTime range0, QDateTime range1)
{
    EmployeeDetailedReport* report;
    report = new EmployeeDetailedReport;

    QSqlQuery get(serverConnections::getInstance()->getserverConnections("general"));

    QString sql;
    sql = "SELECT * FROM `ModifySalary` WHERE `Empid` = :Empid AND (`Date` BETWEEN :Range0 AND :Range1); ";

    get.prepare(sql);

    get.bindValue(":Empid", empId);
    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    modifySalaryModel tmp;
    tmp.setEmployeeID(empId);

    while (get.next())
    {
        tmp.setAdminID     (get.value("Uid").toString());
        tmp.setAmount      (get.value("Amount").toDouble());
        tmp.setDateOfModify(get.value("Date").toDateTime());
        tmp.setNewSalary   (get.value("NewSalary").toDouble());
        tmp.setReason      (get.value("Reason").toString());
        tmp.setType        (get.value("Type").toChar().toLatin1());

        report->addSalaryModification(tmp);
    }

    sql = "SELECT * FROM `Vacation` WHERE `Empid` = :Empid AND (`SDate` BETWEEN :Range0 AND :Range1);";

    get.prepare(sql);

    get.bindValue(":Empid", empId);
    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    holidayModel holi;
    holi.setEmpID(empId);

    while (get.next())
    {
        holi.setAdminID     (get.value("Uid").toString());
        holi.setBackDate    (get.value("EDate").toDate());
        holi.setLeaveDate   (get.value("SDate").toDate());
        holi.setDisc        (get.value("Disc").toDouble());
        holi.setLeaveNotes  (get.value("Notes").toString());
        holi.setLeaveReasons(get.value("Reason").toString());

        report->addHoliday(holi);
    }

    sql = "SELECT * FROM `Late` WHERE `Empid` = :Empid AND (`Sate` BETWEEN :Range0 AND :Range1);";

    get.prepare(sql);

    get.bindValue(":Empid", empId);
    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    dailyLateReportModel late;
    late.setEmployeeID(empId);

    while (get.next())
    {
        late.setAdminID(get.value("Uid").toString());
        late.setDateOfLate(get.value("Date").toDateTime());
        late.setLateTime(get.value("Amount").toInt());
        late.setReasons(get.value("Reason").toString());

        report->addLateReport(late);
    }

    return report;
}
