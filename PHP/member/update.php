<?php
include("head.php");
include("common.php");

$id = $_GET['id'];
$name = $_GET['name'];
$phone = $_GET['phone'];
$gender = $_GET['gender'];
$age = $_GET['age'];

echo($name);

 $sql = "UPDATE member SET name = '$name', phone = '$phone', gender = '$gender', age = '$age' WHERE id = '$id'";

echo("이름: ".$_GET['name']."<br>");
echo("전화번호: ".$_GET['phone']."<br>");
echo("성별: ".$_GET['gender']."<br>");
echo("나이: ".$_GET['age']."<br>");

 echo($sql);
 $result = mysqli_query($connect, $sql);
 print_r("result: [" . $result . "]");

include('foot.php');