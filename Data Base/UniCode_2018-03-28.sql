# ************************************************************
# Sequel Pro SQL dump
# Version 4541
#
# http://www.sequelpro.com/
# https://github.com/sequelpro/sequelpro
#
# Host: 127.0.0.1 (MySQL 5.6.35)
# Database: UniCode
# Generation Time: 2018-03-28 15:32:52 +0000
# ************************************************************


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


# Dump of table Agent
# ------------------------------------------------------------

CREATE TABLE `Agent` (
  `Aid` varchar(20) NOT NULL DEFAULT '',
  `Website` varchar(30) NOT NULL DEFAULT '',
  `Fax` varchar(15) NOT NULL DEFAULT '',
  PRIMARY KEY (`Aid`),
  CONSTRAINT `agent_ibfk_1` FOREIGN KEY (`Aid`) REFERENCES `Seller` (`Sellid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Brand
# ------------------------------------------------------------

CREATE TABLE `Brand` (
  `Name` varchar(30) NOT NULL DEFAULT '',
  `CompanyName` varchar(30) NOT NULL DEFAULT '',
  `Region` varchar(20) NOT NULL DEFAULT '',
  `Producerid` varchar(20) NOT NULL DEFAULT '',
  PRIMARY KEY (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Customer
# ------------------------------------------------------------

CREATE TABLE `Customer` (
  `CusPhone` varchar(15) NOT NULL DEFAULT '',
  `Name` varchar(60) NOT NULL DEFAULT '',
  `Address` varchar(120) NOT NULL DEFAULT '',
  `Email` varchar(60) NOT NULL DEFAULT '',
  `Age` int(11) unsigned NOT NULL,
  `KnownFrom` varchar(20) NOT NULL DEFAULT '',
  PRIMARY KEY (`CusPhone`),
  KEY `KnownFrom` (`KnownFrom`),
  CONSTRAINT `customer_ibfk_1` FOREIGN KEY (`KnownFrom`) REFERENCES `Seller` (`Sellid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Delegate
# ------------------------------------------------------------

CREATE TABLE `Delegate` (
  `Delid` varchar(20) NOT NULL DEFAULT '',
  `Fixed` char(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Delid`),
  CONSTRAINT `delegate_ibfk_1` FOREIGN KEY (`Delid`) REFERENCES `Seller` (`Sellid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table DelgateCustomers
# ------------------------------------------------------------

CREATE TABLE `DelgateCustomers` (
  `Delid` varchar(20) NOT NULL DEFAULT '',
  `CusPhone` varchar(15) NOT NULL DEFAULT '',
  PRIMARY KEY (`Delid`,`CusPhone`),
  KEY `CusPhone` (`CusPhone`),
  CONSTRAINT `delgatecustomers_ibfk_1` FOREIGN KEY (`Delid`) REFERENCES `Delegate` (`Delid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `delgatecustomers_ibfk_2` FOREIGN KEY (`CusPhone`) REFERENCES `Customer` (`CusPhone`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table DepartEmp
# ------------------------------------------------------------

CREATE TABLE `DepartEmp` (
  `Empid` varchar(20) NOT NULL DEFAULT '',
  `DepName` varchar(30) NOT NULL DEFAULT '',
  PRIMARY KEY (`Empid`,`DepName`),
  KEY `DepName` (`DepName`),
  CONSTRAINT `departemp_ibfk_1` FOREIGN KEY (`Empid`) REFERENCES `Employee` (`Empid`),
  CONSTRAINT `departemp_ibfk_2` FOREIGN KEY (`DepName`) REFERENCES `Department` (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Department
# ------------------------------------------------------------

CREATE TABLE `Department` (
  `Name` varchar(30) NOT NULL DEFAULT '',
  `Manager` varchar(20) NOT NULL,
  `Type` varchar(30) NOT NULL DEFAULT '',
  PRIMARY KEY (`Name`),
  KEY `Manager` (`Manager`),
  CONSTRAINT `department_ibfk_1` FOREIGN KEY (`Manager`) REFERENCES `Employee` (`Empid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Employee
# ------------------------------------------------------------

CREATE TABLE `Employee` (
  `Empid` varchar(20) NOT NULL DEFAULT '',
  `Name` varchar(60) NOT NULL DEFAULT '',
  `SSN` varchar(14) NOT NULL DEFAULT '',
  `NickName` varchar(15) NOT NULL DEFAULT '',
  `BirthDate` date NOT NULL,
  `Address` varchar(100) NOT NULL DEFAULT '',
  `PhoneNum` varchar(15) NOT NULL DEFAULT '',
  `Email` varchar(60) DEFAULT NULL,
  `ShiftBeg` time NOT NULL,
  `ShiftEnd` time NOT NULL,
  `ClearSalary` double NOT NULL,
  `Certti` varchar(20) NOT NULL DEFAULT '',
  PRIMARY KEY (`Empid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Evaluation
# ------------------------------------------------------------

CREATE TABLE `Evaluation` (
  `CusPhone` varchar(15) NOT NULL DEFAULT '',
  `Type` varchar(20) NOT NULL DEFAULT '',
  `Date` datetime NOT NULL,
  `Value` int(10) unsigned NOT NULL DEFAULT '0',
  `OrderCode` varchar(20) NOT NULL DEFAULT '',
  `Notes` varchar(120) DEFAULT NULL,
  PRIMARY KEY (`CusPhone`,`Date`),
  CONSTRAINT `evaluation_ibfk_1` FOREIGN KEY (`CusPhone`) REFERENCES `Customer` (`CusPhone`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Importaion
# ------------------------------------------------------------

CREATE TABLE `Importaion` (
  `Code` varchar(20) NOT NULL DEFAULT '',
  `Importid` varchar(20) NOT NULL DEFAULT '',
  `Date` datetime NOT NULL,
  PRIMARY KEY (`Code`),
  KEY `Importid` (`Importid`),
  CONSTRAINT `importaion_ibfk_1` FOREIGN KEY (`Importid`) REFERENCES `Importer` (`Importid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Importer
# ------------------------------------------------------------

CREATE TABLE `Importer` (
  `Importid` varchar(20) NOT NULL DEFAULT '',
  `CompanyName` varchar(35) NOT NULL DEFAULT '',
  `UsualDate` date NOT NULL,
  PRIMARY KEY (`Importid`),
  CONSTRAINT `importer_ibfk_1` FOREIGN KEY (`Importid`) REFERENCES `Employee` (`Empid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table ImportItem
# ------------------------------------------------------------

CREATE TABLE `ImportItem` (
  `Impid` varchar(20) NOT NULL DEFAULT '',
  `PID` varchar(20) NOT NULL DEFAULT '',
  `Quantity` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`Impid`,`PID`),
  KEY `PID` (`PID`),
  CONSTRAINT `importitem_ibfk_1` FOREIGN KEY (`Impid`) REFERENCES `Importaion` (`Code`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `importitem_ibfk_2` FOREIGN KEY (`PID`) REFERENCES `Product` (`Pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Invoice
# ------------------------------------------------------------

CREATE TABLE `Invoice` (
  `Invid` varchar(20) NOT NULL DEFAULT '',
  `CusPhone` varchar(15) NOT NULL DEFAULT '',
  `Deposit` double NOT NULL,
  `Remain` double NOT NULL,
  `Total` double NOT NULL,
  `Date` datetime NOT NULL,
  `Seller` varchar(20) NOT NULL DEFAULT '',
  PRIMARY KEY (`Invid`),
  KEY `CusPhone` (`CusPhone`),
  KEY `Seller` (`Seller`),
  CONSTRAINT `invoice_ibfk_1` FOREIGN KEY (`CusPhone`) REFERENCES `Customer` (`CusPhone`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `invoice_ibfk_2` FOREIGN KEY (`Seller`) REFERENCES `Employee` (`Empid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table InvoiceItem
# ------------------------------------------------------------

CREATE TABLE `InvoiceItem` (
  `Invid` varchar(20) NOT NULL DEFAULT '',
  `PID` varchar(20) NOT NULL DEFAULT '',
  `Quantity` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`Invid`,`PID`),
  KEY `PID` (`PID`),
  CONSTRAINT `invoiceitem_ibfk_1` FOREIGN KEY (`Invid`) REFERENCES `Invoice` (`Invid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `invoiceitem_ibfk_2` FOREIGN KEY (`PID`) REFERENCES `Product` (`Pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Late
# ------------------------------------------------------------

CREATE TABLE `Late` (
  `Empid` varchar(20) NOT NULL DEFAULT '',
  `Uid` varchar(20) NOT NULL,
  `Date` datetime NOT NULL,
  `Amount` int(11) NOT NULL,
  `Reason` varchar(120) DEFAULT '',
  PRIMARY KEY (`Empid`,`Date`),
  KEY `Uid` (`Uid`),
  CONSTRAINT `late_ibfk_1` FOREIGN KEY (`Empid`) REFERENCES `unicode`.`Employee` (`Empid`),
  CONSTRAINT `late_ibfk_2` FOREIGN KEY (`Uid`) REFERENCES `Employee` (`Empid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table ModifySalary
# ------------------------------------------------------------

CREATE TABLE `ModifySalary` (
  `Empid` varchar(20) NOT NULL DEFAULT '',
  `Uid` varchar(20) NOT NULL,
  `Date` datetime NOT NULL,
  `type` char(1) NOT NULL DEFAULT '',
  `Amount` double NOT NULL,
  `Reason` varchar(120) DEFAULT '',
  `NewSalary` double NOT NULL,
  PRIMARY KEY (`Empid`,`Date`),
  KEY `Uid` (`Uid`),
  CONSTRAINT `modifysalary_ibfk_1` FOREIGN KEY (`Empid`) REFERENCES `Employee` (`Empid`),
  CONSTRAINT `modifysalary_ibfk_2` FOREIGN KEY (`Uid`) REFERENCES `Employee` (`Empid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Order
# ------------------------------------------------------------

CREATE TABLE `Order` (
  `OrderCode` varchar(20) NOT NULL DEFAULT '',
  `Delegate` varchar(20) NOT NULL DEFAULT '',
  `Date` datetime NOT NULL,
  `Invoiceid` varchar(20) NOT NULL DEFAULT '',
  PRIMARY KEY (`OrderCode`),
  KEY `Delegate` (`Delegate`),
  CONSTRAINT `order_ibfk_1` FOREIGN KEY (`Delegate`) REFERENCES `Employee` (`Empid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Product
# ------------------------------------------------------------

CREATE TABLE `Product` (
  `Pid` varchar(20) NOT NULL DEFAULT '',
  `Name` varchar(30) NOT NULL DEFAULT '',
  `UnitPrice` double NOT NULL,
  `ImageView` longblob,
  `BarCode` varchar(15) NOT NULL DEFAULT '',
  `BName` varchar(30) NOT NULL DEFAULT '',
  PRIMARY KEY (`Pid`),
  KEY `BName` (`BName`),
  CONSTRAINT `product_ibfk_1` FOREIGN KEY (`BName`) REFERENCES `Brand` (`Name`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Seller
# ------------------------------------------------------------

CREATE TABLE `Seller` (
  `Sellid` varchar(20) NOT NULL DEFAULT '',
  `Type` varchar(30) NOT NULL DEFAULT '',
  PRIMARY KEY (`Sellid`),
  CONSTRAINT `seller_ibfk_1` FOREIGN KEY (`Sellid`) REFERENCES `Employee` (`Empid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Vacation
# ------------------------------------------------------------

CREATE TABLE `Vacation` (
  `Empid` varchar(20) NOT NULL DEFAULT '',
  `Uid` varchar(20) NOT NULL,
  `SDate` date NOT NULL,
  `EDate` date NOT NULL,
  `Reason` varchar(120) NOT NULL DEFAULT '',
  `Notes` varchar(120) NOT NULL DEFAULT '',
  `Disc` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`Empid`,`SDate`),
  KEY `Uid` (`Uid`),
  CONSTRAINT `vacation_ibfk_1` FOREIGN KEY (`Empid`) REFERENCES `Employee` (`Empid`),
  CONSTRAINT `vacation_ibfk_2` FOREIGN KEY (`Uid`) REFERENCES `Employee` (`Empid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Ware
# ------------------------------------------------------------

CREATE TABLE `Ware` (
  `Wareid` varchar(20) NOT NULL DEFAULT '',
  `Name` varchar(30) NOT NULL DEFAULT '',
  `Type` varchar(15) NOT NULL DEFAULT '',
  PRIMARY KEY (`Wareid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table WareProduct
# ------------------------------------------------------------

CREATE TABLE `WareProduct` (
  `WCode` varchar(20) NOT NULL DEFAULT '',
  `PID` varchar(20) NOT NULL DEFAULT '',
  `Quantity` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`WCode`,`PID`),
  KEY `PID` (`PID`),
  CONSTRAINT `wareproduct_ibfk_1` FOREIGN KEY (`WCode`) REFERENCES `Ware` (`Wareid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `wareproduct_ibfk_2` FOREIGN KEY (`PID`) REFERENCES `Product` (`Pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



CREATE TABLE `Efficiency` (
  `EmpId` varchar(20) NOT NULL DEFAULT '',
  `AdminId` varchar(20) NOT NULL DEFAULT '',
  `Amount` double NOT NULL DEFAULT '0',
  `Date` datetime NOT NULL,
  PRIMARY KEY (`EmpId`),
  KEY `AdminId` (`AdminId`),
  CONSTRAINT `efficiency_ibfk_1` FOREIGN KEY (`EmpId`) REFERENCES `Employee` (`Empid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `efficiency_ibfk_2` FOREIGN KEY (`AdminId`) REFERENCES `Employee` (`Empid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;




/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
