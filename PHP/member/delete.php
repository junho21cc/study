<?php
include('head.php');
include('common.php');

$id = $_GET['id'];



$sql = "DELETE FROM member WHERE id = '$id'";

echo($sql);
$result = mysqli_query($connect, $sql);
print_r("result: [" . $result . "]");

header('Location: http://www.junho.ml/member/list.php');

include('foot.php');
