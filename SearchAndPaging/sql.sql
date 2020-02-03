/*
SQLyog Ultimate v12.09 (64 bit)
MySQL - 5.5.56 : Database - test
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`test` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `test`;

/*Table structure for table `test1` */

DROP TABLE IF EXISTS `test1`;

CREATE TABLE `test1` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(25) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `outpatientNum` varchar(20) DEFAULT NULL COMMENT '门诊号',
  `part` varchar(20) DEFAULT NULL COMMENT '部位',
  `sex` char(4) DEFAULT NULL COMMENT '性别',
  `age` int(11) DEFAULT NULL COMMENT '年龄',
  `admissionNum` varchar(20) DEFAULT NULL COMMENT '住院号',
  `clinicalDiagnosis` varchar(50) DEFAULT NULL COMMENT '临床诊断',
  `classification` char(20) DEFAULT NULL COMMENT '科别',
  `bedNum` int(11) DEFAULT NULL COMMENT '床号',
  `doctor` char(20) DEFAULT NULL COMMENT '送诊医师',
  `starttime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;

/*Data for the table `test1` */

insert  into `test1`(`id`,`name`,`outpatientNum`,`part`,`sex`,`age`,`admissionNum`,`clinicalDiagnosis`,`classification`,`bedNum`,`doctor`,`starttime`) values (7,'顺丰速递','22','三个','女',6,'33','微软','顺丰',454,'微软','2018-03-16 19:33:13'),(8,'电风扇','34','是','男',1,'34','士大夫','是否',34,'士大夫','2018-03-16 19:34:52'),(9,'都市封神','34','个','男',1,'34','个','地方',34,'发给','2018-03-16 19:34:47'),(10,'都市封神','34','个','男',1,'34','个','地方',34,'发给','2018-03-15 19:34:41'),(11,'4545','45','45','男',1,'45','45','45',45,'45','2018-03-24 19:34:31'),(12,'微软','432','234','男',1,'234','234','微软',234,'234','2018-02-27 19:34:23'),(13,'士大夫','234','234','男',1,'234','234','士大夫',324,'234','2018-03-07 19:33:53'),(14,'微软','23','34','男',1,'34','34',' 是',234,'234','2018-02-26 19:33:44'),(15,'放大','324','345','女',8,'345','345','是否',345,'345','2018-03-16 19:33:39'),(16,'F','34','45','女',4,'45','45','45',45,'45','2018-03-13 19:33:29'),(17,'34','34','34','女',4,'34','34','34',34,'65','2018-03-16 19:33:26'),(18,'45','45','45','女',45,'45','45','45',45,'45','2018-03-16 19:34:59');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
