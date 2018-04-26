#include "repositories/employeerepository.h"
employeeRepository::employeeRepository()
{

}
bool employeeRepository::addEmployee(employeesModel employee)
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
bool employeeRepository::deleteEmployee(QString empId)
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

    InsertQuery.prepare("INSERT INTO `ModifySalary` (`Empid`, `Uid`, `Date`, `type`, `amount`, `Reasons`) "
                        "Values (:Empid, :Uid, :Date, :type, :amount, :Reasons)" );

    InsertQuery.bindValue(":Empid",modify.getEmployeeID() );
    InsertQuery.bindValue(":Uid", modify.getAdminID());
    InsertQuery.bindValue(":Date", modify.getDateOfModify() );
    InsertQuery.bindValue(":type", modify.getType());
    InsertQuery.bindValue(":amount", modify.getAmount());
    InsertQuery.bindValue(":Reasons", modify.getReason());

    return InsertQuery.exec();
}
bool employeeRepository::deleteModification(QString empId, QDateTime date)
{
    QSqlQuery deleteQuery(serverConnections::getInstance()->getserverConnections("general"));

    deleteQuery.prepare("DELETE FROM `ModifySalary` WHERE `Empid` = :Empid AND `Date` = :Date ");

    deleteQuery.bindValue(":Empid", empId);
    deleteQuery.bindValue(":Date", date);

    return deleteQuery.exec();

}
bool employeeRepository::updateSalaryModification(modifySalaryModel modify)
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

bool employeeRepository::addHoliday(holidayModel holiday)
{
    QSqlQuery InsertQuery(serverConnections::getInstance()->getserverConnections("general"));

    InsertQuery.prepare("INSERT INTO `Vacation` (`Empid` ,`Uid` ,`SDate` ,`EDate` ,`Reason` ,`Notes` ,`Disc` )"
                        "VALUES (:Empid, :Uid, :SDate, :EDate, :Reason, :Notes, :Disc) " );

    InsertQuery.bindValue(":Empid", holiday.getEmpID())         ;
    InsertQuery.bindValue(":Uid", holiday.getAdminID())         ;
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
bool employeeRepository::deleteHoliday(QString empId, QDate date)
{
    QSqlQuery deleteQuery(serverConnections::getInstance()->getserverConnections("general"));

    deleteQuery.prepare("DELETE FROM `Vacation` WHERE `Empid` = :Empid AND `SDate` = :SDate ");

    deleteQuery.bindValue(":Empid", empId);
    deleteQuery.bindValue(":SDate", date);

    return deleteQuery.exec();

}

EmployeeDetailedReport* employeeRepository::generateDetailedReport(QString empId, QDateTime range0, QDateTime range1)
{
    EmployeeDetailedReport* report;
    report = new EmployeeDetailedReport;
    //get Modfiy salary in the range
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
        tmp.setReason      (get.value("Reason").toString());
        tmp.setType        (get.value("Type").toChar().toLatin1());

        report->addSalaryModification(tmp);
    }

    //get holiday in the range
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

    //get late in the range
    sql = "SELECT * FROM `Late` WHERE `Empid` = :Empid AND (`Date` BETWEEN :Range0 AND :Range1);";

    get.prepare(sql);

    get.bindValue(":Empid", empId);
    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    dailyLateReportModel late;
    late.setEmployeeID(empId);

    while (get.next())
    {
        late.setAdminID   (get.value("Uid").toString());
        late.setDateOfLate(get.value("Date").toDateTime());
        late.setAmount    (get.value("Amount").toInt());
        late.setReasons   (get.value("Reason").toString());

        report->addLateReport(late);
    }

    // get efficiency in the range
    sql = "SELECT * FROM `Efficiency` WHERE `Empid` = :Empid AND (`Date` BETWEEN :Range0 AND :Range1);";

    get.prepare(sql);

    get.bindValue(":Empid", empId);
    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    efficiencymodel effic;
    effic.setEmpId(empId);

    while (get.next())
    {
        effic.setAdminId   (get.value("Uid").toString());
        effic.setDate      (get.value("Date").toDateTime());
        effic.setAmount     (get.value("Amount").toInt());

        report->addEfficiency(effic);
    }

    return report;
}

EmployeesGeneralReport* employeeRepository::generateGeneralReport(QDate range0, QDate range1, QString department)
{
    EmployeesGeneralReport* report;
    report = new EmployeesGeneralReport;

    QSqlQuery get(serverConnections::getInstance()->getserverConnections("general"));

    QString sql, disc, bonus, lend, lates, holidays, disHoliday, effic, dept;

    if (department == "All" || department == "all")
        dept = "";
    else
        dept = " AND `Department` = '"+ department + "'";
    disc       = "SELECT SUM(`Amount`) FROM `ModifySalary` as m   WHERE m.`Empid` = e.`Empid` AND (`Date`  BETWEEN :Range0 AND :Range1) AND `type` = 'd' ";
    bonus      = "SELECT SUM(`Amount`) FROM `ModifySalary` as m   WHERE m.`Empid` = e.`Empid` AND (`Date`  BETWEEN :Range0 AND :Range1) AND `type` = 'z'";
    lend       = "SELECT SUM(`Amount`) FROM `ModifySalary` as m   WHERE m.`Empid` = e.`Empid` AND (`Date`  BETWEEN :Range0 AND :Range1) AND `type` = 's'";
    lates      = "SELECT SUM(`Amount`) FROM `Lates` as m          WHERE m.`Empid` = e.`Empid` AND (`Date`  BETWEEN :range0 AND :range1)";
    holidays   = "SELECT COUNT(*)      FROM `Vacation` as m       WHERE m.`Empid` = e.`Empid` AND (`SDate` BETWEEN :range0 AND :range1)";
    disHoliday = "SELECT SUM(`Disc`)   FROM `Vacation` as m       WHERE m.`Empid` = e.`Empid` AND (`SDate` BETWEEN :range0 AND :range1)";
    effic      = "SELECT SUM(`Amount`) FROM `Efficiency` as m     WHERE m.`Empid` = e.`Empid` AND (`Date`  BETWEEN :range0 AND :range1)";

    if (dept != "")
    {
        disc       += dept;
        bonus      += dept;
        lend       += dept;
        lates      += dept;
        holidays   += dept;
        disHoliday += dept;
        effic      += dept;
    }

    sql        = "SELECT e.`EmpId`, e.`Name`, e.`Department` , e.`ClearSalary`, ("+ disc +") as dis,"
                 " ("+ bonus +") as bonus, ("+ lend +") as lend, ("+ lates +") as lend,"
                 " ("+ holidays +") as holi, ("+ disHoliday +") as disHoli, ("+ effic +") as effic FROM `Employee` as e";
    get.prepare(sql);

    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    EmployeesGeneralReport::SingleReport sreport;

    while (get.next())
    {
        sreport.empId                 = get.value(0).toString();
        sreport.empName               = get.value(1).toString();
        sreport.DepName               = get.value(2).toString();
        sreport.ClearSalary           = get.value(3).toDouble();
        sreport.TotalBonus            = get.value(4).toDouble();
        sreport.TotalLend             = get.value(5).toDouble();
        sreport.TotalDaysLate         = get.value(6).toInt();
        sreport.TotalHolidayDays      = get.value(7).toInt();
        sreport.TotalHolidaysDiscount = get.value(8).toDouble();
        sreport.TotalEfficiencyAmount = get.value(9).toDouble();

        report->addSingleReport(sreport);
    }

    return report;
}

bool employeeRepository::addEfficiency(efficiencymodel efficiency)
{
    QSqlQuery InsertQuery(serverConnections::getInstance()->getserverConnections("general"));

    InsertQuery.prepare("INSERT INTO `efficiency` (`empId` ,`adminId` ,`amount` ,`date` )"
                        "VALUES (:Empid, :Uid, :amount, :Date " );

    InsertQuery.bindValue(":Empid", efficiency.getEmpId())     ;
    InsertQuery.bindValue(":Uid", efficiency.getAdminId())     ;
    InsertQuery.bindValue(":amount", efficiency.getAmount())   ;
    InsertQuery.bindValue(":Date", efficiency.getDate())       ;

    return InsertQuery.exec();

}
bool employeeRepository::deleteEfficiency(QString empId)
{
    QSqlQuery deleteQuery(serverConnections::getInstance()->getserverConnections("general"));

    deleteQuery.prepare("DELETE FROM `efficiency` WHERE `empId` = :Empid ");

    deleteQuery.bindValue(":Empid", empId);

    return deleteQuery.exec();


}
bool employeeRepository::updateEfficiency(efficiencymodel efficiency)
{
    efficiencycontroller effController ;
    QMap<QString,QVariant> attribute = effController.getAttributeNotDefault(efficiency);
    QSqlQuery updateQuery(serverConnections::getInstance()->getserverConnections("general"));
    QString query="UPDATE `efficiency` SET ";
    for(QString feildName:attribute.keys())
    {
        query+="`";
        query+=feildName;
        query+="` = :";
        query+=feildName;
        query+=" ";
    }
    query+=" WHERE `empId`= :Empid ";
    updateQuery.prepare(query);
    for(QString feildName:attribute.keys())
    {
        updateQuery.bindValue(":"+feildName,attribute.value(feildName));
    }
    updateQuery.bindValue(":Empid",efficiency.getEmpId());
    return updateQuery.exec();

}

SalaryReport* employeeRepository::generateSalaryReport(QDate range0, QDate range1, QString department)
{
    SalaryReport* report = new SalaryReport;

    QSqlQuery get(serverConnections::getInstance()->getserverConnections("general"));

    QString totalDis, totalLend, totalBonus, totalHoliDis, clear, dept;

    if (department == "All" || department == "all")
        dept = "";
    else
        dept = " AND `Department` = '"+ department + "';";

    totalDis     = "SELECT SUM(`Amount`)      FROM `ModifySalary`  WHERE (`Date`  BETWEEN :Range0 AND :Range1) AND `type` = 'd'";
    totalBonus   = "SELECT SUM(`Amount`)      FROM `ModifySalary`  WHERE (`Date`  BETWEEN :Range0 AND :Range1) AND `type` = 'z'";
    totalLend    = "SELECT SUM(`Amount`)      FROM `ModifySalary`  WHERE (`Date`  BETWEEN :Range0 AND :Range1) AND `type` = 's'";
    totalHoliDis = "SELECT SUM(`Disc`)        FROM `Vacation`      WHERE (`SDate` BETWEEN :range0 AND :range1)";
    clear        = "SELECT SUM(`ClearSalary`) FROM `Employee` ";

    if (dept != "")
    {
        totalDis        += dept;
        totalBonus      += dept;
        totalLend       += dept;
        totalHoliDis    += dept;
        clear           += "WHERE `Department` = '"+ department + "';";
    }

    // Total Discount
    get.prepare(totalDis);

    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    get.first();

    report->TotalDiscount = get.value(0).toDouble();

    // Total Bouns
    get.prepare(totalBonus);

    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    get.first();

    report->TotalBonus = get.value(0).toDouble();

    // Total Lend
    get.prepare(totalLend);

    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    get.first();

    report->TotalLend = get.value(0).toDouble();

    // Total Holiday Discount
    get.prepare(totalHoliDis);

    get.bindValue(":Range0", range0);
    get.bindValue(":Range1", range1);

    get.first();

    report->TotalHolidaysDiscount = get.value(0).toDouble();

    // Total Clear Salaries

    get.exec(clear);

    get.first();

    report->ClearSalary = get.value(0).toDouble();

    // Payed Salary
    report->CalculatePayedSalary();

    return report;
}
