<?php
include('head.php');

$mysql_hostname = 'localhost';//localhost
$mysql_username = 'member';//root
$mysql_password = '!Member1234.';
$mysql_database = 'member';//testdb
$mysql_table = 'member';


$connect = mysqli_connect($mysql_hostname, $mysql_username, $mysql_password, $mysql_database);
mysqli_select_db($connect, $mysql_database) or die('DB 선택 실패');
$sql = "SELECT * FROM ".$mysql_table;
$result = mysqli_query($connect, $sql);

while($info=mysqli_fetch_array($result)){

    echo $info[$mysql_col1]." | ";
    echo $info[$mysql_col2]." | ";
    echo $info[$mysql_col3]."<br/>\n";
}

mysqli_close($connect);

include('foot.php');