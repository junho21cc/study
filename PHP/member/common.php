<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

$mysql_hostname = 'localhost';//localhost
$mysql_username = 'member';//root
$mysql_password = '!Member1234.';
$mysql_database = 'member';//testdb
$mysql_table = 'member';

$connect = mysqli_connect($mysql_hostname, $mysql_username, $mysql_password, $mysql_database);
mysqli_query($connect, "set session character_set_connection=utf8;");
mysqli_query($connect, "set session character_set_results=utf8;");
mysqli_query($connect, "set session character_set_client=utf8;");
mysqli_select_db($connect, $mysql_database) or die('DB 선택 실패');

