/*
 Navicat Premium Data Transfer

 Source Server         : Morgan2
 Source Server Type    : MySQL
 Source Server Version : 50533
 Source Host           : 192.168.1.146:3306
 Source Schema         : sanane

 Target Server Type    : MySQL
 Target Server Version : 50533
 File Encoding         : 65001

 Date: 06/04/2018 18:15:54
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for item_rent
-- ----------------------------
DROP TABLE IF EXISTS `item_rent`;
CREATE TABLE `item_rent`  (
  `id` int(11) DEFAULT 0,
  `owner_id` int(11) DEFAULT 0,
  `count` tinyint(3) DEFAULT 0,
  `vnum` int(11) DEFAULT 0,
  `socket0` int(11) DEFAULT 0,
  `socket1` int(11) DEFAULT 0,
  `socket2` int(11) DEFAULT 0,
  `socket3` int(11) DEFAULT NULL,
  `socket4` int(11) DEFAULT NULL,
  `socket5` int(11) DEFAULT NULL,
  `attrtype0` tinyint(4) DEFAULT 0,
  `attrvalue0` smallint(6) DEFAULT 0,
  `attrtype1` tinyint(4) DEFAULT 0,
  `attrvalue1` smallint(6) DEFAULT 0,
  `attrtype2` tinyint(4) DEFAULT 0,
  `attrvalue2` smallint(6) DEFAULT 0,
  `attrtype3` tinyint(4) DEFAULT 0,
  `attrvalue3` smallint(6) DEFAULT 0,
  `attrtype4` tinyint(4) DEFAULT 0,
  `attrvalue4` smallint(6) DEFAULT 0,
  `attrtype5` tinyint(4) DEFAULT 0,
  `attrvalue5` smallint(6) DEFAULT 0,
  `attrtype6` tinyint(4) DEFAULT 0,
  `attrvalue6` smallint(6) DEFAULT 0
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Fixed;

SET FOREIGN_KEY_CHECKS = 1;
