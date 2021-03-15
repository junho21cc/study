<?php
include('head.php');

error_reporting(E_ALL);
ini_set('display_errors', '1');

$mysql_hostname = 'localhost';//localhost
$mysql_username = 'member';//root
$mysql_password = '!Member1234.';
$mysql_database = 'member';//testdb
$mysql_table = 'member';

$name = $_GET['name'];
$phone = $_GET['phone'];
$gender = $_GET['gender'];
$age = $_GET['age'];

$connect = mysqli_connect($mysql_hostname, $mysql_username, $mysql_password, $mysql_database);
mysqli_query("set session character_set_connection=utf8;");
mysqli_query("set session character_set_results=utf8;");
mysqli_query("set session character_set_client=utf8;");
mysqli_select_db($connect, $mysql_database) or die('DB 선택 실패');
$sql = "INSERT INTO member(name, phone, gender, age) VALUES ('$name', '$phone', '$gender', $age)";

$result = mysqli_query($connect, $sql);

echo("이름: ".$_GET['name']."<br>");
echo("전화번호: ".$_GET['phone']."<br>");
echo("성별: ".$_GET['gender']."<br>");
echo("나이: ".$_GET['age']."<br>");

echo($sql);
print_r("result: [" . $result . "]");
echo(mysqli_error($connect));

include('foot.php');
