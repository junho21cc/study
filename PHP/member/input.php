<?php
include('head.php');
include('common.php');

$name = $_GET['name'];
$phone = $_GET['phone'];
$gender = $_GET['gender'];
$age = $_GET['age'];

$sql = "INSERT INTO member(name, phone, gender, age) VALUES ('$name', '$phone', '$gender', $age)";

$result = mysqli_query($connect, $sql);

echo("이름: ".$name."<br>");
echo("전화번호: ".$phone."<br>");
echo("성별: ".$gender."<br>");
echo("나이: ".$age."<br>");

echo($sql);
print_r("result: [" . $result . "]");
echo(mysqli_error($connect));

include('foot.php');
