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