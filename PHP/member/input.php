<?php
include('head.php');
include('common.php');

$result = mysqli_query($connect, $sql);

$name = $_GET['name'];
$phone = $_GET['phone'];
$gender = $_GET['gender'];
$age = $_GET['age'];

$sql = "INSERT INTO member(name, phone, gender, age) VALUES ('$name', '$phone', '$gender', $age)";

echo("이름: ".$_GET['name']."<br>");
echo("전화번호: ".$_GET['phone']."<br>");
echo("성별: ".$_GET['gender']."<br>");
echo("나이: ".$_GET['age']."<br>");

echo($sql);
print_r("result: [" . $result . "]");
echo(mysqli_error($connect));

include('foot.php');
