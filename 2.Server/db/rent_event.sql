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

 Date: 06/04/2018 18:17:18
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for rent_event
-- ----------------------------
DROP TABLE IF EXISTS `rent_event`;
CREATE TABLE `rent_event`  (
  `owner_id` int(11) DEFAULT 0,
  `item_id` int(11) DEFAULT 0,
  `rent` int(11) DEFAULT NULL,
  `target_id` int(11) DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of rent_event
-- ----------------------------
INSERT INTO `rent_event` VALUES (10032, 10001389, 1494144403, 10014);
INSERT INTO `rent_event` VALUES (10035, 10001395, 1493215170, 10014);
INSERT INTO `rent_event` VALUES (10042, 10000017, 1493871601, 10041);
INSERT INTO `rent_event` VALUES (10043, 10000019, 1493872097, 10041);
INSERT INTO `rent_event` VALUES (10041, 10000035, 1493872178, 10043);
INSERT INTO `rent_event` VALUES (10041, 10000042, 1493892043, 10043);

SET FOREIGN_KEY_CHECKS = 1;
