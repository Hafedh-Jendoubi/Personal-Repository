-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 14, 2024 at 02:20 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.1.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `siyahi`
--

-- --------------------------------------------------------

--
-- Table structure for table `achat`
--

CREATE TABLE `achat` (
  `id` int(11) NOT NULL,
  `image` varchar(255) NOT NULL,
  `type` varchar(255) NOT NULL,
  `description` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `achat`
--

INSERT INTO `achat` (`id`, `image`, `type`, `description`) VALUES
(6, '33483fd211ef00aae608e5de092892b4.jpg', 'Voiture', 'Nouvelle voiture'),
(7, '6b9f636c0fad9ca3f6ff776188aa8ab1.jpg', 'Appartement', 'Cet appartement moderne, spacieux, lumineux, confortable, élégant, équipé, cosy, chic offre une vue panoramique et un agencement minimaliste.'),
(8, '9670252f46c68d00e654b45c0e0f0e8a.jpg', 'Voiture', 'Une voiture rouge : audacieuse, dynamique, passionnée. Carrosserie brillante, lignes fluides. Intérieur sophistiqué, sièges cuir, expérience excitante, symbole de style et de vitesse.'),
(10, '07f5a8a7cb8600c44e073fa6b6e028e5.jpg', 'Terrain', 'Terrain à vendre : spacieux, bien situé, idéal pour construction. Vue panoramique, nature préservée, potentiel d\'aménagement, investissement prometteur, opportunité unique.');

-- --------------------------------------------------------

--
-- Table structure for table `calendar`
--

CREATE TABLE `calendar` (
  `id` int(11) NOT NULL,
  `title` varchar(255) NOT NULL,
  `start` date NOT NULL,
  `end` date NOT NULL,
  `description` varchar(255) NOT NULL,
  `all_day` tinyint(1) NOT NULL,
  `background_color` varchar(255) NOT NULL,
  `border_color` varchar(255) NOT NULL,
  `text_color` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `commande`
--

CREATE TABLE `commande` (
  `id` int(11) NOT NULL,
  `user_id` int(11) DEFAULT NULL,
  `object` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `compte_client`
--

CREATE TABLE `compte_client` (
  `id` int(11) NOT NULL,
  `user_id` int(11) DEFAULT NULL,
  `rib` bigint(20) NOT NULL,
  `created_at` date NOT NULL,
  `solde` double NOT NULL,
  `service_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `compte_client`
--

INSERT INTO `compte_client` (`id`, `user_id`, `rib`, `created_at`, `solde`, `service_id`) VALUES
(8, 5, 3160104781243901, '2024-05-12', 60000, 6),
(9, 7, 4663722234855623, '2024-04-24', 6000, 8),
(10, 14, 5124850597180037, '2024-04-24', 1200, 4),
(11, 7, 1659238887826290, '2024-04-25', 2000, 4),
(12, 7, 1334797144294515, '2024-04-25', 5020, 6),
(14, 5, 2567665092777278, '2024-05-09', 50000, 1),
(15, 29, 10053895175272022, '2024-05-11', 15000, 3),
(17, 15, 5157595351575953, '2024-05-13', 20500, 1);

-- --------------------------------------------------------

--
-- Table structure for table `conge`
--

CREATE TABLE `conge` (
  `id` int(11) NOT NULL,
  `user_id` int(11) DEFAULT NULL,
  `description` varchar(255) NOT NULL,
  `date_debut` date NOT NULL,
  `date_fin` date NOT NULL,
  `justification` varchar(255) DEFAULT NULL,
  `date_demande` date NOT NULL DEFAULT current_timestamp(),
  `type_conge` varchar(255) DEFAULT NULL,
  `status` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `conge`
--

INSERT INTO `conge` (`id`, `user_id`, `description`, `date_debut`, `date_fin`, `justification`, `date_demande`, `type_conge`, `status`) VALUES
(28, 15, 'bbbb', '2024-04-30', '2024-05-02', 'Maladie ', '2024-04-24', NULL, 1),
(29, 15, '2 jrs', '2024-05-07', '2024-05-17', 'Maladie ', '2024-04-25', NULL, 1),
(50, 14, 'marhbee', '2024-05-14', '2024-05-16', NULL, '2024-05-08', 'Mariage', 1),
(52, 13, 'Ma congé', '2024-05-17', '2024-05-23', '6641548e45be2.jpg', '2024-05-13', 'Maladie', 1),
(58, 15, 'Svp!', '2024-05-27', '2024-05-31', '65e8b14df12b2.png', '2024-05-13', 'Vacances', 0);

-- --------------------------------------------------------

--
-- Table structure for table `credit`
--

CREATE TABLE `credit` (
  `id` int(11) NOT NULL,
  `user_id` int(11) DEFAULT NULL,
  `solde_demande` double NOT NULL,
  `date_debut_paiement` date NOT NULL,
  `nbr_mois_paiement` int(11) NOT NULL,
  `description` varchar(255) NOT NULL,
  `contrat` varchar(255) DEFAULT NULL,
  `type_credit_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `credit`
--

INSERT INTO `credit` (`id`, `user_id`, `solde_demande`, `date_debut_paiement`, `nbr_mois_paiement`, `description`, `contrat`, `type_credit_id`) VALUES
(2, 5, 50000, '2025-04-11', 36, 'bmw', '', 1),
(3, 7, 8000, '2026-04-24', 60, 'rienn', '', 2),
(5, 7, 5000, '2024-05-11', 60, 'j\'en ai besoin', 'Images/ATTESTATION REUSSITE 3 eme ISIMM22-23 ISKANDER KACEM.jpg', 3),
(10, 5, 70000, '2024-05-16', 150180, 'J\'ai besoin de KIA', NULL, 2),
(11, 5, 70000, '2024-05-16', 120, 'Mon voiture', 'Images/5abb0d5e-e665-4607-b25e-ce0afc52bb1b_241016677_946144235932534_2698860531229489283_n.jpg', 1),
(12, 29, 40000, '2024-05-22', 120, 'RAYEEN', '66414b17de61c.png', 1),
(28, 29, 123456792, '2024-05-14', 15, 'ettestset', '65e8a7978d2f9.png', 1),
(30, 29, 1458, '2024-05-16', 10, 'rezrezrzerzre', '6641497ab3193.png', 1),
(33, 31, 25000, '2024-05-16', 10, 'Skanderrr', '66423ee83a0b2.jpg', 3);

-- --------------------------------------------------------

--
-- Table structure for table `demande_achat`
--

CREATE TABLE `demande_achat` (
  `id` int(11) NOT NULL,
  `user_id` int(11) DEFAULT NULL,
  `achat_id` int(11) DEFAULT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `date_demande` date NOT NULL,
  `num_tel` varchar(255) NOT NULL,
  `type_paiement` varchar(255) NOT NULL,
  `cin` int(11) NOT NULL,
  `adresse` varchar(255) NOT NULL,
  `etatdemande` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `demande_achat`
--

INSERT INTO `demande_achat` (`id`, `user_id`, `achat_id`, `nom`, `prenom`, `date_demande`, `num_tel`, `type_paiement`, `cin`, `adresse`, `etatdemande`) VALUES
(6, 2, 6, 'tesst', 'tests', '2024-05-08', '14515936', 'cheque', 0, 'hay sahafa', 'demande refu'),
(8, 5, 7, 'tesette', 'tezqtet', '2024-05-08', '54152934', 'cheque', 12345678, 'hshshshshfdsfdsfds', 'En attente'),
(13, 5, 6, 'Ahlem', 'Mhamdi', '2024-05-08', '53404903', 'cheque', 14221216, 'Mourouj, Tunisia', 'En attente'),
(14, 5, 6, 'Mhamdi', 'Ahlem', '2024-05-08', '53404903', 'cheque', 14221216, 'Mourouj, Tunisia', 'En attente'),
(15, 5, 8, 'Mhamdi', 'Ahlem', '2024-05-08', '53404903', 'cheque', 14221216, 'Mourouj, Tunisia', 'En attente'),
(17, 5, 6, 'Mhamdi', 'Ahlem', '2024-05-09', '53404903', 'cheque', 14221216, 'Mourouj, Tunisia', 'En attente'),
(18, 5, 6, 'Mhamdi', 'Ahlem', '2024-05-09', '53404903', 'cheque', 14221216, 'Mourouj, Tunisia', 'En attente');

-- --------------------------------------------------------

--
-- Table structure for table `doctrine_migration_versions`
--

CREATE TABLE `doctrine_migration_versions` (
  `version` varchar(191) NOT NULL,
  `executed_at` datetime DEFAULT NULL,
  `execution_time` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `doctrine_migration_versions`
--

INSERT INTO `doctrine_migration_versions` (`version`, `executed_at`, `execution_time`) VALUES
('DoctrineMigrations\\Version20240306163401', '2024-03-06 17:34:05', 634),
('DoctrineMigrations\\Version20240306164723', '2024-03-06 17:47:29', 82);

-- --------------------------------------------------------

--
-- Table structure for table `limitation_conge`
--

CREATE TABLE `limitation_conge` (
  `id` int(11) NOT NULL,
  `annee` int(11) NOT NULL,
  `mois` varchar(255) NOT NULL,
  `nbr_jours` int(11) DEFAULT NULL,
  `user_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `limitation_conge`
--

INSERT INTO `limitation_conge` (`id`, `annee`, `mois`, `nbr_jours`, `user_id`) VALUES
(1, 2022, 'Février', 11, 15),
(2, 2022, 'Février', 11, 15),
(3, 2025, 'Avril ', 5, 14),
(4, 2026, 'Mai', 1, NULL),
(5, 2024, 'Juillet ', 9, 15),
(6, 2024, 'Juin', 6, NULL),
(10, 2025, 'Février', 5, 13),
(11, 2027, 'Juillet ', 7, 11),
(12, 2025, 'Février', 2, 13);

-- --------------------------------------------------------

--
-- Table structure for table `messenger_messages`
--

CREATE TABLE `messenger_messages` (
  `id` bigint(20) NOT NULL,
  `body` longtext NOT NULL,
  `headers` longtext NOT NULL,
  `queue_name` varchar(190) NOT NULL,
  `created_at` datetime NOT NULL,
  `available_at` datetime NOT NULL,
  `delivered_at` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `messenger_messages`
--

INSERT INTO `messenger_messages` (`id`, `body`, `headers`, `queue_name`, `created_at`, `available_at`, `delivered_at`) VALUES
(10, 'O:36:\\\"Symfony\\\\Component\\\\Messenger\\\\Envelope\\\":2:{s:44:\\\"\\0Symfony\\\\Component\\\\Messenger\\\\Envelope\\0stamps\\\";a:1:{s:46:\\\"Symfony\\\\Component\\\\Messenger\\\\Stamp\\\\BusNameStamp\\\";a:1:{i:0;O:46:\\\"Symfony\\\\Component\\\\Messenger\\\\Stamp\\\\BusNameStamp\\\":1:{s:55:\\\"\\0Symfony\\\\Component\\\\Messenger\\\\Stamp\\\\BusNameStamp\\0busName\\\";s:21:\\\"messenger.bus.default\\\";}}}s:45:\\\"\\0Symfony\\\\Component\\\\Messenger\\\\Envelope\\0message\\\";O:51:\\\"Symfony\\\\Component\\\\Mailer\\\\Messenger\\\\SendEmailMessage\\\":2:{s:60:\\\"\\0Symfony\\\\Component\\\\Mailer\\\\Messenger\\\\SendEmailMessage\\0message\\\";O:28:\\\"Symfony\\\\Component\\\\Mime\\\\Email\\\":6:{i:0;N;i:1;N;i:2;s:56:\\\"<p>Une nouvelle réponse de congé a été ajoutée.</p>\\\";i:3;s:5:\\\"utf-8\\\";i:4;a:0:{}i:5;a:2:{i:0;O:37:\\\"Symfony\\\\Component\\\\Mime\\\\Header\\\\Headers\\\":2:{s:46:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\Headers\\0headers\\\";a:3:{s:4:\\\"from\\\";a:1:{i:0;O:47:\\\"Symfony\\\\Component\\\\Mime\\\\Header\\\\MailboxListHeader\\\":5:{s:50:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0name\\\";s:4:\\\"From\\\";s:56:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0lineLength\\\";i:76;s:50:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0lang\\\";N;s:53:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0charset\\\";s:5:\\\"utf-8\\\";s:58:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\MailboxListHeader\\0addresses\\\";a:1:{i:0;O:30:\\\"Symfony\\\\Component\\\\Mime\\\\Address\\\":2:{s:39:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Address\\0address\\\";s:24:\\\"bettaieb.ahmed@esprit.tn\\\";s:36:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Address\\0name\\\";s:0:\\\"\\\";}}}}s:2:\\\"to\\\";a:1:{i:0;O:47:\\\"Symfony\\\\Component\\\\Mime\\\\Header\\\\MailboxListHeader\\\":5:{s:50:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0name\\\";s:2:\\\"To\\\";s:56:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0lineLength\\\";i:76;s:50:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0lang\\\";N;s:53:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0charset\\\";s:5:\\\"utf-8\\\";s:58:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\MailboxListHeader\\0addresses\\\";a:1:{i:0;O:30:\\\"Symfony\\\\Component\\\\Mime\\\\Address\\\":2:{s:39:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Address\\0address\\\";s:24:\\\"ahmedbettaib56@gmail.com\\\";s:36:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Address\\0name\\\";s:0:\\\"\\\";}}}}s:7:\\\"subject\\\";a:1:{i:0;O:48:\\\"Symfony\\\\Component\\\\Mime\\\\Header\\\\UnstructuredHeader\\\":5:{s:50:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0name\\\";s:7:\\\"Subject\\\";s:56:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0lineLength\\\";i:76;s:50:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0lang\\\";N;s:53:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\AbstractHeader\\0charset\\\";s:5:\\\"utf-8\\\";s:55:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\UnstructuredHeader\\0value\\\";s:36:\\\"Nouvelle réponse de congé ajoutée\\\";}}}s:49:\\\"\\0Symfony\\\\Component\\\\Mime\\\\Header\\\\Headers\\0lineLength\\\";i:76;}i:1;N;}}s:61:\\\"\\0Symfony\\\\Component\\\\Mailer\\\\Messenger\\\\SendEmailMessage\\0envelope\\\";N;}}', '[]', 'default', '2024-05-13 19:17:14', '2024-05-13 19:17:14', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `reclamation`
--

CREATE TABLE `reclamation` (
  `id` int(11) NOT NULL,
  `object` varchar(255) NOT NULL,
  `description` varchar(255) NOT NULL,
  `user_id` int(11) DEFAULT NULL,
  `date_creation` date NOT NULL,
  `auteur` varchar(255) NOT NULL,
  `status` tinyint(1) DEFAULT 0,
  `email` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `reclamation`
--

INSERT INTO `reclamation` (`id`, `object`, `description`, `user_id`, `date_creation`, `auteur`, `status`, `email`) VALUES
(56, 'Frais Bancaires Inattendus', 'Description de la réclamation', 5, '2024-04-24', 'Auteur de la réclamation', 0, 'valide@mail.com'),
(58, 'Frais Bancaires Inattendus', '.', 7, '2024-05-01', 'aaa', 0, 'test.iheb@gmail.com'),
(65, 'Demande Extrait', 'Haaaafedh', 5, '2024-05-06', 'Iheeeb', 0, 'valide@mail.com'),
(68, 'Virement Non Reçu', 'zze', 29, '2024-05-07', 'zeze', 0, 'uu@u.dom'),
(70, 'Frais Bancaires Inattendus', 'haahha', 29, '2024-05-08', 'Hafedh', 0, 'hafedh.jendoubi@siyahi.tn'),
(71, 'Frais Bancaires Inattendus', 'Hahaha', 5, '2024-05-08', 'aeraer', 0, 'hafedh@gmail.com'),
(72, 'Blocage de Carte Bancaire', 'Mon carte est bloqué', 5, '2024-05-09', 'Ahlem', 0, 'ahlem.mhamdi@siyahi.tn'),
(75, 'Virement Non Reçu', 'Tesest', 31, '2024-05-13', 'test', 0, 'test@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `reponse_conge`
--

CREATE TABLE `reponse_conge` (
  `id` int(11) NOT NULL,
  `conge_id` int(11) DEFAULT NULL,
  `user_id` int(11) DEFAULT NULL,
  `date_debut` date DEFAULT NULL,
  `date_fin` date DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL,
  `Date_creation` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `reponse_conge`
--

INSERT INTO `reponse_conge` (`id`, `conge_id`, `user_id`, `date_debut`, `date_fin`, `description`, `Date_creation`) VALUES
(20, 28, 2, '2024-05-27', '2024-05-31', 'D\'accord', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `reponse_credit`
--

CREATE TABLE `reponse_credit` (
  `id` int(11) NOT NULL,
  `credit_id` int(11) DEFAULT NULL,
  `user_id` int(11) DEFAULT NULL,
  `solde_a_payer` double NOT NULL,
  `date_debut_paiement` date NOT NULL,
  `nbr_mois_paiement` int(11) NOT NULL,
  `description` varchar(255) NOT NULL,
  `auto_financement` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `reponse_credit`
--

INSERT INTO `reponse_credit` (`id`, `credit_id`, `user_id`, `solde_a_payer`, `date_debut_paiement`, `nbr_mois_paiement`, `description`, `auto_financement`) VALUES
(13, 2, 13, 55730, '2025-04-11', 36, 'credit voiture accepté', 11146),
(16, 3, 13, 8876.8, '2026-04-24', 60, 'accceepté', 1775.36),
(17, 5, 13, 5648, '2024-05-11', 60, 'acceepté', 0),
(21, 10, 2, 25000, '2024-05-23', 120, 'mabrouk', 0),
(22, 33, 2, 25000, '2024-05-16', 120, 'Acceptééeeeee', 0);

-- --------------------------------------------------------

--
-- Table structure for table `reponse_reclamation`
--

CREATE TABLE `reponse_reclamation` (
  `id` int(11) NOT NULL,
  `description` varchar(255) NOT NULL,
  `reclamation_id` int(11) DEFAULT NULL,
  `user_id` int(11) DEFAULT NULL,
  `date_creation` date NOT NULL,
  `auteur` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `reponse_reclamation`
--

INSERT INTO `reponse_reclamation` (`id`, `description`, `reclamation_id`, `user_id`, `date_creation`, `auteur`) VALUES
(32, 'Fdsfdsfsd', 65, NULL, '2024-05-08', 'Haafedhh'),
(33, 'Voilaa', 65, NULL, '2024-05-08', 'Hafedh'),
(37, 'Je vais contacter le team responsable bientot!', 68, NULL, '2024-05-12', 'Hafedh');

-- --------------------------------------------------------

--
-- Table structure for table `reset_password_request`
--

CREATE TABLE `reset_password_request` (
  `id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `selector` varchar(20) NOT NULL,
  `hashed_token` varchar(100) NOT NULL,
  `requested_at` datetime NOT NULL COMMENT '(DC2Type:datetime_immutable)',
  `expires_at` datetime NOT NULL COMMENT '(DC2Type:datetime_immutable)'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `service`
--

CREATE TABLE `service` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `description` varchar(255) NOT NULL,
  `frais` double DEFAULT NULL,
  `expiration` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `service`
--

INSERT INTO `service` (`id`, `name`, `description`, `frais`, `expiration`) VALUES
(1, 'Business', 'C\'est un type de service', NULL, NULL),
(3, 'Courant', 'C\'est un type de compte de dépôt offert par les institutions financières. Il est principalement utilisé pour les transactions quotidiennes.', NULL, NULL),
(4, 'Epargne', 'C\'est un type de compte de dépôt offert par les institutions financières. Il est principalement utilisé stocker l\'argent.', NULL, NULL),
(5, 'Etranger', 'C\'est un compte bancaire ouvert dans un pays autre que le pays de résidence du titulaire du compte.', NULL, NULL),
(6, 'VIP', 'C\'est un compte déstiné principalement aux hommes d\'affaires et aux clients qui possèdenet un grand volume de transactions mensuelles.', NULL, NULL),
(8, 'ghjghn', 'n nb,gh,', NULL, NULL),
(11, 'hamroun', 'skdjfnskdjvsv', NULL, NULL),
(12, 'hamroun', 'skdjfnskdjvsv', NULL, NULL),
(77, 'zargaaaaa', 'azkjzndazf', 18, '2028-04-16'),
(80, 'test', 'test', 20, '2025-04-04'),
(82, 'esprit', 'espritespritespritespritesprit', 15, '2024-04-30'),
(83, 'Iheb', 'IHebIHebIHebIHeb', 50, '2024-04-30'),
(86, 'test', 'This is a service test', 15, '2026-04-22'),
(87, 'madrid', 'hala madrid', 50, '2024-05-29'),
(88, 'Hafeddh', 'Jendoubi', 80, '2024-05-20');

-- --------------------------------------------------------

--
-- Table structure for table `transaction`
--

CREATE TABLE `transaction` (
  `id` int(11) NOT NULL,
  `ribSent` bigint(20) NOT NULL,
  `ribRec` bigint(20) NOT NULL,
  `cash` float NOT NULL,
  `date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `transaction`
--

INSERT INTO `transaction` (`id`, `ribSent`, `ribRec`, `cash`, `date`) VALUES
(1, 10053895175272022, 1334797144294515, 5000, '2024-05-11');

-- --------------------------------------------------------

--
-- Table structure for table `type_credit`
--

CREATE TABLE `type_credit` (
  `id` int(11) NOT NULL,
  `nom_type_credit` varchar(255) DEFAULT NULL,
  `taux_crédit_direct` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `type_credit`
--

INSERT INTO `type_credit` (`id`, `nom_type_credit`, `taux_crédit_direct`) VALUES
(1, 'Credit voiture', 11.46),
(2, 'Credit d\'habitat', 10.96),
(3, 'Credit consommation', 12.96),
(4, 'Credit amenagement', 11.86);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `email` varchar(180) NOT NULL,
  `roles` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL COMMENT '(DC2Type:json)' CHECK (json_valid(`roles`)),
  `password` varchar(255) NOT NULL,
  `first_name` varchar(15) NOT NULL,
  `last_name` varchar(20) NOT NULL,
  `gender` varchar(1) NOT NULL,
  `address` varchar(50) DEFAULT NULL,
  `phone_number` int(11) DEFAULT NULL,
  `cin` int(11) NOT NULL,
  `created_at` datetime NOT NULL COMMENT '(DC2Type:datetime_immutable)',
  `image` varchar(255) DEFAULT NULL,
  `old_email` varchar(255) NOT NULL,
  `activity` varchar(1) NOT NULL,
  `verified` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id`, `email`, `roles`, `password`, `first_name`, `last_name`, `gender`, `address`, `phone_number`, `cin`, `created_at`, `image`, `old_email`, `activity`, `verified`) VALUES
(2, 'hafedh.jendoubi@siyahi.tn', '[\"ROLE_SUPER_ADMIN\"]', '$2y$13$gWIDoxmPVr9yJ8FJ2VwItOH6NM.gQVaikCyghSaiAciBB4iGk4KvK', 'Jendoubi', 'Hafedh', 'M', 'Manouba', 95052214, 14515936, '2024-02-17 14:14:45', '6444f15a62df6a0e9096d999b2d060e4.jpg', 'hafedh.jendoubi@esprit.tn', 'T', 0),
(5, 'ahlem.mhamdi@siyahi.tn', '[\"ROLE_USER\"]', '$2y$13$gWIDoxmPVr9yJ8FJ2VwItOH6NM.gQVaikCyghSaiAciBB4iGk4KvK', 'Ahlem', 'Mhamdi', 'F', 'Mourouj, Tunisia', 53404903, 14221216, '2024-02-18 18:39:55', '78f1ff3123bff099a0bdd8a709ecd775.jpg', 'ahlem.mhamdi@esprit.tn', 'T', 0),
(7, 'Majdi.Jendoubi@siyahi.tn', '[\"ROLE_USER\"]', '$2y$13$M.6wLjPwI16MqITj4va/WuOIbO6akhG064oaocxFDKaBseMBg4jGq', 'Jendoubi', 'Majdi', 'M', 'Jdeida, Manouba', 52114132, 14223441, '2024-02-19 15:43:50', '10be5ddf9143c8a08c6027e40e7731ea.jpg', 'majdi.jendoubi@esprit.tn', 'T', 0),
(11, 'ben hamroun.yessine@siyahi.tn', '[\"ROLE_STAFF\"]', '$2y$13$oXLYs/7P91qbVPLUt4.poeq65VdJVBVSBgXfNOQj88Cs4L/L8mjCy', 'Ben Hamroun', 'Yessine', 'M', 'Hay Sahafa, Ariana Essoghra', 50443421, 14333200, '2024-02-21 14:46:23', '093495839684c297c6650a1d1ecf8df4.jpg', 'yessine.benhamroun@esprit.tn', 'T', 0),
(13, 'skander.kacem@siyahi.tn', '[\"ROLE_STAFF\"]', '$2y$13$oKuF9f.yAPTWEBb8yyez2uYchWYgg1JfqW5tAaTJpHcvuPy6DdeTO', 'Kacem', 'Skander', 'M', 'Hay Sahafa, Ariana Essoghra', 96505443, 14033213, '2024-02-21 16:05:14', 'c5457df5e577597371bb9115fe6bb3a1.jpg', 'skander.kacem@esprit.tn', 'T', 0),
(14, 'bettaieb.ahmed@siyahi.tn', '[\"ROLE_ADMIN\"]', '$2y$13$IL3V1bEUQcesDnInhHqoren2lk0.c/kZbZ8eM3noKVOXoWFkAWn3S', 'Bettaieb', 'Ahmed', 'M', 'Hay Sahafa, Ariana Essoghra', 97205143, 14033214, '2024-02-21 16:05:51', '111befb12ff4e12ee0cf226de92706d8.jpg', 'ahmed.bettaieb@esprit.tn', 'T', 0),
(15, 'iheb.amri@siyahi.tn', '[\"ROLE_ADMIN\"]', '$2y$13$nvrbBVdZLtl60SrEa.Xd7ODTRQumEm8ZXyyX0ErwGa0Yeptck9rO.', 'Iheb', 'Amri', 'M', 'Sidi Bouzid, Tunis', 24339403, 14330030, '2024-02-21 19:38:46', '144a7e6cf05bfa83cb674cd50b0c9d64.jpg', 'iheb.amri@esprit.tn', 'T', 0),
(29, 'rayen.klai@siyahi.tn', '[\"ROLE_USER\"]', '$2y$13$ILpehm1LlqTI4SfgQPu67evcXziDyR75Wy36fO52.u2G8rxF0azuW', 'Klai', 'Rayen', 'M', 'Ariana, Hay Ettadhamon', 97660554, 14003493, '2024-05-11 00:04:00', '6db5ad0aa5fc3ffba77fd34460bc34f6.jpg', 'rayen.klai@gmail.com', 'T', 0),
(30, 'nour.trabelsi@siyahi.tn', '[\"ROLE_USER\"]', '$2y$13$ht32RborZ3rr2yDtKec46.8zX8ZJ8Etn3D5mWFGqDtWqYNZSuvoZ.', 'Nour', 'Trabelsi', 'F', 'Manouba, Jdeida', 25044345, 14230214, '2024-05-11 16:37:44', '952bf13fe496ddc573b44e694d52e4dd.jpg', 'nour.trabelsi@gmail.com', 'T', 0),
(31, 'yessine.jmai@siyahi.tn', '[\"ROLE_USER\"]', '$2y$13$z9Sno4QSW1LG8wI2Stw0Gu1OueRAFXd4CvfksvlsaOBxJT6.c3lxq', 'Yessine', 'Jmai', 'M', 'Hay fatouma, Bardo', 58443220, 14032990, '2024-05-11 22:33:37', '7b652808dbc93a4b547c608afc833d84.jpg', 'yessine.jmai@gmail.com', 'T', 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `achat`
--
ALTER TABLE `achat`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `calendar`
--
ALTER TABLE `calendar`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `commande`
--
ALTER TABLE `commande`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_6EEAA67DA76ED395` (`user_id`);

--
-- Indexes for table `compte_client`
--
ALTER TABLE `compte_client`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_1DDD5D62A76ED395` (`user_id`),
  ADD KEY `IDX_1DDD5D62ED5CA9E6` (`service_id`),
  ADD KEY `UNIQ_1DDD5D62BFB7B5B6` (`rib`) USING BTREE;

--
-- Indexes for table `conge`
--
ALTER TABLE `conge`
  ADD PRIMARY KEY (`id`),
  ADD KEY `UNIQ_2ED89348A76ED395` (`user_id`) USING BTREE;

--
-- Indexes for table `credit`
--
ALTER TABLE `credit`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_1CC16EFEA76ED395` (`user_id`),
  ADD KEY `IDX_1CC16EFE7AC06EE9` (`type_credit_id`);

--
-- Indexes for table `demande_achat`
--
ALTER TABLE `demande_achat`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_D077077FA76ED395` (`user_id`),
  ADD KEY `IDX_D077077FFE95D117` (`achat_id`);

--
-- Indexes for table `doctrine_migration_versions`
--
ALTER TABLE `doctrine_migration_versions`
  ADD PRIMARY KEY (`version`);

--
-- Indexes for table `limitation_conge`
--
ALTER TABLE `limitation_conge`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_user` (`user_id`);

--
-- Indexes for table `messenger_messages`
--
ALTER TABLE `messenger_messages`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_75EA56E0FB7336F0` (`queue_name`),
  ADD KEY `IDX_75EA56E0E3BD61CE` (`available_at`),
  ADD KEY `IDX_75EA56E016BA31DB` (`delivered_at`);

--
-- Indexes for table `reclamation`
--
ALTER TABLE `reclamation`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_CE606404A76ED395` (`user_id`);

--
-- Indexes for table `reponse_conge`
--
ALTER TABLE `reponse_conge`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_C131E82BCAAC9A59` (`conge_id`),
  ADD KEY `IDX_C131E82BA76ED395` (`user_id`);

--
-- Indexes for table `reponse_credit`
--
ALTER TABLE `reponse_credit`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_C895B767CE062FF9` (`credit_id`),
  ADD KEY `IDX_C895B767A76ED395` (`user_id`);

--
-- Indexes for table `reponse_reclamation`
--
ALTER TABLE `reponse_reclamation`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_C7CB51012D6BA2D9` (`reclamation_id`),
  ADD KEY `IDX_C7CB5101A76ED395` (`user_id`);

--
-- Indexes for table `reset_password_request`
--
ALTER TABLE `reset_password_request`
  ADD PRIMARY KEY (`id`),
  ADD KEY `IDX_7CE748AA76ED395` (`user_id`);

--
-- Indexes for table `service`
--
ALTER TABLE `service`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `transaction`
--
ALTER TABLE `transaction`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `type_credit`
--
ALTER TABLE `type_credit`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `UNIQ_8D93D649E7927C74` (`email`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `achat`
--
ALTER TABLE `achat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `calendar`
--
ALTER TABLE `calendar`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `commande`
--
ALTER TABLE `commande`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `compte_client`
--
ALTER TABLE `compte_client`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;

--
-- AUTO_INCREMENT for table `conge`
--
ALTER TABLE `conge`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=59;

--
-- AUTO_INCREMENT for table `credit`
--
ALTER TABLE `credit`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=36;

--
-- AUTO_INCREMENT for table `demande_achat`
--
ALTER TABLE `demande_achat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `limitation_conge`
--
ALTER TABLE `limitation_conge`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `messenger_messages`
--
ALTER TABLE `messenger_messages`
  MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `reclamation`
--
ALTER TABLE `reclamation`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=76;

--
-- AUTO_INCREMENT for table `reponse_conge`
--
ALTER TABLE `reponse_conge`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT for table `reponse_credit`
--
ALTER TABLE `reponse_credit`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT for table `reponse_reclamation`
--
ALTER TABLE `reponse_reclamation`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38;

--
-- AUTO_INCREMENT for table `reset_password_request`
--
ALTER TABLE `reset_password_request`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `service`
--
ALTER TABLE `service`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=90;

--
-- AUTO_INCREMENT for table `transaction`
--
ALTER TABLE `transaction`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `type_credit`
--
ALTER TABLE `type_credit`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=36;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `commande`
--
ALTER TABLE `commande`
  ADD CONSTRAINT `FK_6EEAA67DA76ED395` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`);

--
-- Constraints for table `conge`
--
ALTER TABLE `conge`
  ADD CONSTRAINT `FK_2ED89348A76ED395` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`);

--
-- Constraints for table `credit`
--
ALTER TABLE `credit`
  ADD CONSTRAINT `FK_1CC16EFE7AC06EE9` FOREIGN KEY (`type_credit_id`) REFERENCES `type_credit` (`id`),
  ADD CONSTRAINT `FK_1CC16EFEA76ED395` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`);

--
-- Constraints for table `demande_achat`
--
ALTER TABLE `demande_achat`
  ADD CONSTRAINT `FK_D077077FA76ED395` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`),
  ADD CONSTRAINT `FK_D077077FFE95D117` FOREIGN KEY (`achat_id`) REFERENCES `achat` (`id`);

--
-- Constraints for table `limitation_conge`
--
ALTER TABLE `limitation_conge`
  ADD CONSTRAINT `FK_user` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`);

--
-- Constraints for table `reclamation`
--
ALTER TABLE `reclamation`
  ADD CONSTRAINT `FK_CE606404A76ED395` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`);

--
-- Constraints for table `reponse_conge`
--
ALTER TABLE `reponse_conge`
  ADD CONSTRAINT `FK_C131E82BA76ED395` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`),
  ADD CONSTRAINT `FK_C131E82BCAAC9A59` FOREIGN KEY (`conge_id`) REFERENCES `conge` (`id`);

--
-- Constraints for table `reponse_credit`
--
ALTER TABLE `reponse_credit`
  ADD CONSTRAINT `FK_C895B767A76ED395` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`),
  ADD CONSTRAINT `FK_C895B767CE062FF9` FOREIGN KEY (`credit_id`) REFERENCES `credit` (`id`);

--
-- Constraints for table `reponse_reclamation`
--
ALTER TABLE `reponse_reclamation`
  ADD CONSTRAINT `FK_C7CB51012D6BA2D9` FOREIGN KEY (`reclamation_id`) REFERENCES `reclamation` (`id`),
  ADD CONSTRAINT `FK_C7CB5101A76ED395` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`);

--
-- Constraints for table `reset_password_request`
--
ALTER TABLE `reset_password_request`
  ADD CONSTRAINT `FK_7CE748AA76ED395` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
