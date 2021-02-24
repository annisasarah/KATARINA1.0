-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 10, 2021 at 08:08 AM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.2.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `datasensor`
--

-- --------------------------------------------------------

--
-- Table structure for table `sensorlembab`
--

CREATE TABLE `sensorlembab` (
  `nilai` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `sensorlembab`
--

INSERT INTO `sensorlembab` (`nilai`) VALUES
(0);

-- --------------------------------------------------------

--
-- Table structure for table `sensorsuhu`
--

CREATE TABLE `sensorsuhu` (
  `nilai` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `sensorsuhu`
--

INSERT INTO `sensorsuhu` (`nilai`) VALUES
(0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `sensorlembab`
--
ALTER TABLE `sensorlembab`
  ADD PRIMARY KEY (`nilai`);

--
-- Indexes for table `sensorsuhu`
--
ALTER TABLE `sensorsuhu`
  ADD PRIMARY KEY (`nilai`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
