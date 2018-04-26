DROP TABLE `DepartEmp`;

ALTER TABLE `Employee` 
ADD COLUMN `Added By` VARCHAR(20) NULL AFTER `Certti`,
ADD INDEX `f1_idx` (`Added By` ASC);
ALTER TABLE `Employee` 
ADD CONSTRAINT `f1`
  FOREIGN KEY (`Added By`)
  REFERENCES `Employee` (`Empid`)
  ON DELETE CASCADE
  ON UPDATE CASCADE;

ALTER TABLE `Employee` 
ADD COLUMN `Department` VARCHAR(30) NOT NULL AFTER `Added By`,
ADD INDEX `f2_idx` (`Department` ASC);
ALTER TABLE `Employee` 
ADD CONSTRAINT `f2`
  FOREIGN KEY (`Department`)
  REFERENCES `Department` (`Name`)
  ON DELETE NO ACTION
  ON UPDATE NO ACTION;
