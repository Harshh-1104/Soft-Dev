-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 26, 2025 at 08:10 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `library_db`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `BookPrice` (IN `id` INT)   BEGIN
    SELECT price 
    FROM books
    WHERE book_id = id;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `BooksByAuthor` (IN `author_name` VARCHAR(100))   BEGIN
    SELECT * 
    FROM books
    WHERE author = author_name;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `Book_by_IdAndPrice` (IN `id` INT, IN `g_price` INT)   BEGIN
    SELECT id AS book_id, g_price AS price;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `Calc_B_Prices` ()   BEGIN
    DECLARE price1 INT DEFAULT 210;
    DECLARE price2 INT DEFAULT 180;
    DECLARE price3 INT DEFAULT 170;
    DECLARE sum_prices INT;
    DECLARE avg_price int;

    SET sum_prices = price1 + price2 + price3;
    SET avg_price = sum_prices / 3;
   
    SELECT 
        sum_prices AS total_price, 
        avg_price AS average_price; 
     
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `CheckBookPriceById` (IN `id` INT)   BEGIN
    DECLARE t_price INT;

    SELECT price INTO t_price FROM books WHERE book_id = id;

    IF t_price > 200 THEN
        SELECT CONCAT('the book price is above 200 (price: ', t_price, ')') AS message;
    ELSE
        SELECT CONCAT('the book price is 200 or below (price: ', t_price, ')') AS message;
    END IF;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ForNewBook` (IN `n_book_id` INT, IN `n_title` VARCHAR(200), IN `n_author` VARCHAR(100), IN `n_publisher` VARCHAR(100), IN `n_year` INT, IN `n_price` INT, IN `n_genre` VARCHAR(100), IN `n_author_id` INT)   BEGIN
    INSERT INTO books (book_id,title, author, publisher, year_of_publication, price, genre, author_id)
    VALUES (n_book_id,n_title, n_author, n_publisher, n_year, n_price, n_genre, n_author_id);

    SELECT CONCAT('Book "', n_title, '" inserted successfully') AS confirmation_message;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowAllBooks` ()   BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE g_book_id INT;
    DECLARE g_title VARCHAR(200);
    DECLARE g_author VARCHAR(100);
    DECLARE g_publisher VARCHAR(100);
    DECLARE g_year INT;
    DECLARE g_price INT;
    DECLARE g_genre VARCHAR(100);
    DECLARE g_author_id INT;
    DECLARE cur CURSOR FOR 
        SELECT book_id, title, author, publisher, year_of_publication, price, genre, author_id
        FROM books;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN cur;

    read_loop: LOOP
        FETCH cur INTO g_book_id, g_title, g_author, g_publisher, g_year, g_price, g_genre, g_author_id;

        IF done THEN
            LEAVE read_loop;
        END IF;

        SELECT 
            g_book_id AS book_id,
            g_title AS title,
            g_author AS author,
            g_publisher AS publisher,
            g_year AS year_of_publication,
            g_price AS price,
            g_genre AS genre,
            g_author_id AS author_id;
    END LOOP;

    CLOSE cur;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowAllMembers` ()   BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE g_member_id INT;
    DECLARE g_member_name VARCHAR(200);
    DECLARE g_date_of_membership DATE;
    DECLARE g_email VARCHAR(200);

    DECLARE cur CURSOR FOR 
        SELECT member_id, member_name, date_of_membership, email FROM members;

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN cur;

    member_loop: LOOP
        FETCH cur INTO g_member_id, g_member_name, g_date_of_membership, g_email;
        IF done THEN
            LEAVE member_loop;
        END IF;
        SELECT 
            g_member_id AS member_id,
            g_member_name AS member_name,
            g_date_of_membership AS date_of_membership,
            g_email AS email;
    END LOOP;

    CLOSE cur;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowBooksByAuthor` (IN `g_author` VARCHAR(100))   BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE g_title VARCHAR(100);
    DECLARE cur CURSOR FOR 
        SELECT title FROM books WHERE author = g_author;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN cur;

    books_loop: LOOP
        FETCH cur INTO g_title;
        IF done THEN
            LEAVE books_loop;
        END IF;
        SELECT g_title AS book_title;
    END LOOP;

    CLOSE cur;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowTotalBooks` ()   BEGIN
    SELECT COUNT(*) AS total_books FROM books;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `authors`
--

CREATE TABLE `authors` (
  `author_id` int(11) NOT NULL,
  `first_name` varchar(100) DEFAULT NULL,
  `last_name` varchar(100) DEFAULT NULL,
  `country` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `authors`
--

INSERT INTO `authors` (`author_id`, `first_name`, `last_name`, `country`) VALUES
(1, 'oda', 'monkey', 'japan'),
(2, 'itachi', 'uchiha', 'india'),
(3, 'javier', 'law', 'korea'),
(4, 'kim', 'hyunsoo', 'korea'),
(5, 'endou', 'tatsuya', 'america'),
(6, 'hyuuga', 'natsu', 'canada'),
(7, 'kaku', 'yuuji', 'china'),
(8, 'Muneyuki', 'Kaneshiro', 'japan'),
(9, 'Gege', 'Akutami', 'japan'),
(10, 'Koyoharu', 'Gotouge', 'japan');

-- --------------------------------------------------------

--
-- Table structure for table `books`
--

CREATE TABLE `books` (
  `book_id` int(11) NOT NULL,
  `title` varchar(255) NOT NULL,
  `author` varchar(200) NOT NULL,
  `publisher` varchar(200) NOT NULL,
  `year_of_publication` int(11) DEFAULT NULL,
  `price` int(11) DEFAULT NULL,
  `genre` varchar(100) DEFAULT NULL,
  `author_id` int(11) DEFAULT NULL
) ;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`book_id`, `title`, `author`, `publisher`, `year_of_publication`, `price`, `genre`, `author_id`) VALUES
(1, 'Chainsaw Man', 'Tatsuki Fujimoto', 'Shueisha', 2019, 250, 'Action', 11),
(2, 'the greatest estate developer', 'kim hyunsoo', 'asura scans', 2019, 200, 'Manhwa', 4),
(3, 'spy x family', 'endou tatsuya', 'shueisha', 2019, 150, 'Manga', 5),
(4, 'the apothecary diaries', 'hyuuga natsu', 'square enix books', 2021, 180, 'Manga', 6),
(5, 'Hells paradise ', 'kaku yuuji', 'shueisha', 2012, 230, 'Manga', 7),
(6, 'Blue Lock', 'Muneyuki Kaneshiro', 'Kodansha', 2018, 220, 'Sports', 8),
(7, 'Jujutsu Kaisen', 'Gege Akutami', 'Shueisha', 2018, 210, 'Supernatural', 9),
(8, 'My Hero Academia', 'Kohei Horikoshi', 'Shueisha', 2014, 175, 'Action', 12),
(9, 'Vagabond', 'Takehiko Inoue', 'Kodansha', 1998, 275, 'Historical', 13),
(10, 'Noragami', 'Adachitoka', 'Kodansha', 2010, 210, 'Fantasy', 14);

--
-- Triggers `books`
--
DELIMITER $$
CREATE TRIGGER `book_delete_tri` AFTER DELETE ON `books` FOR EACH ROW BEGIN
    INSERT INTO delete_log (book_id, title, author)
    VALUES (OLD.book_id, OLD.title, OLD.author);
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `update_log` AFTER UPDATE ON `books` FOR EACH ROW BEGIN
    INSERT INTO update_log (book_id, old_title, new_title, old_price, new_price)
    VALUES 
    (
        OLD.book_id,
        OLD.title,
        NEW.title,
        OLD.price,
        NEW.price
    );
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Stand-in structure for view `books_summary`
-- (See below for the actual view)
--
CREATE TABLE `books_summary` (
`title` varchar(255)
,`author` varchar(200)
,`price` int(11)
);

-- --------------------------------------------------------

--
-- Table structure for table `delete_log`
--

CREATE TABLE `delete_log` (
  `log_id` int(11) NOT NULL,
  `book_id` int(11) DEFAULT NULL,
  `title` varchar(200) DEFAULT NULL,
  `author` varchar(100) DEFAULT NULL,
  `deleted_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `delete_log`
--

INSERT INTO `delete_log` (`log_id`, `book_id`, `title`, `author`, `deleted_at`) VALUES
(1, 8, 'Demon Slayer', 'Koyoharu Gotouge', '2025-10-26 14:41:43');

-- --------------------------------------------------------

--
-- Table structure for table `members`
--

CREATE TABLE `members` (
  `member_id` int(11) NOT NULL,
  `member_name` varchar(100) NOT NULL,
  `date_of_membership` date NOT NULL,
  `email` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `members`
--

INSERT INTO `members` (`member_id`, `member_name`, `date_of_membership`, `email`) VALUES
(1, 'harsh', '2023-04-11', 'harsh@email.com'),
(2, 'luffy', '2022-06-22', 'monkey@email.com'),
(3, 'kazuma', '2020-10-10', 'chun@gmail.com'),
(4, 'llyod', '2024-03-18', 'fronterra@gmail.com'),
(5, 'ash', '2020-08-15', 'ash@gmail.com'),
(6, 'eren', '2021-12-22', 'eren@gmail.com'),
(7, 'aqua', '2019-07-03', 'aqua@gmail.com'),
(8, 'sai', '2018-05-19', 'sai@gmail.com'),
(9, 'jin', '2023-09-21', 'jin@gmail.com'),
(10, 'zoro', '2019-10-27', 'zoro@email.com');

-- --------------------------------------------------------

--
-- Table structure for table `members_backup`
--

CREATE TABLE `members_backup` (
  `member_id` int(11) NOT NULL,
  `member_name` varchar(100) NOT NULL,
  `date_of_membership` date NOT NULL,
  `email` varchar(200) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `members_backup`
--

INSERT INTO `members_backup` (`member_id`, `member_name`, `date_of_membership`, `email`) VALUES
(1, 'harsh', '2023-04-11', 'harsh@email.com'),
(2, 'luffy', '2022-06-22', 'monkey@email.com'),
(3, 'anya', '2024-01-10', 'forger@email.com'),
(4, 'llyod', '2020-03-18', 'fronterra@email.com'),
(5, 'maomao', '2024-05-05', 'hehe@email.com');

-- --------------------------------------------------------

--
-- Stand-in structure for view `members_before_2020`
-- (See below for the actual view)
--
CREATE TABLE `members_before_2020` (
`member_id` int(11)
,`member_name` varchar(100)
,`date_of_membership` date
,`email` varchar(100)
);

-- --------------------------------------------------------

--
-- Table structure for table `update_log`
--

CREATE TABLE `update_log` (
  `log_id` int(11) NOT NULL,
  `book_id` int(11) DEFAULT NULL,
  `old_title` varchar(200) DEFAULT NULL,
  `new_title` varchar(200) DEFAULT NULL,
  `old_price` int(11) DEFAULT NULL,
  `new_price` int(11) DEFAULT NULL,
  `update_time` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `update_log`
--

INSERT INTO `update_log` (`log_id`, `book_id`, `old_title`, `new_title`, `old_price`, `new_price`, `update_time`) VALUES
(1, 2, 'the greatest estate developer', 'the greatest estate developer', 210, 200, '2025-10-26 14:14:30'),
(2, 0, 'Chainsaw Man', 'Chainsaw Man', 250, 250, '2025-10-26 15:00:01'),
(3, 5, 'Hells paradise ', 'Hells paradise ', 176, 230, '2025-10-26 17:48:39');

-- --------------------------------------------------------

--
-- Structure for view `books_summary`
--
DROP TABLE IF EXISTS `books_summary`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `books_summary`  AS SELECT `books`.`title` AS `title`, `books`.`author` AS `author`, `books`.`price` AS `price` FROM `books` ;

-- --------------------------------------------------------

--
-- Structure for view `members_before_2020`
--
DROP TABLE IF EXISTS `members_before_2020`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `members_before_2020`  AS SELECT `members`.`member_id` AS `member_id`, `members`.`member_name` AS `member_name`, `members`.`date_of_membership` AS `date_of_membership`, `members`.`email` AS `email` FROM `members` WHERE year(`members`.`date_of_membership`) < 2020 ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `authors`
--
ALTER TABLE `authors`
  ADD PRIMARY KEY (`author_id`);

--
-- Indexes for table `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`book_id`);

--
-- Indexes for table `delete_log`
--
ALTER TABLE `delete_log`
  ADD PRIMARY KEY (`log_id`);

--
-- Indexes for table `members`
--
ALTER TABLE `members`
  ADD PRIMARY KEY (`member_id`);

--
-- Indexes for table `update_log`
--
ALTER TABLE `update_log`
  ADD PRIMARY KEY (`log_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `delete_log`
--
ALTER TABLE `delete_log`
  MODIFY `log_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `update_log`
--
ALTER TABLE `update_log`
  MODIFY `log_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
