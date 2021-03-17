<?php
include('head.php');
include('common.php');

$sql = "SELECT * FROM ".$mysql_table;
$result = mysqli_query($connect, $sql);

echo("<table>
<tr>
    <td>Id</td>
    <td>Name</td>
    <td>Phone</td>
    <td>Gender</td>
    <td>Age</td>
    <td></td>
    <td></td>
</tr>
");

while($info=mysqli_fetch_array($result)){

    echo(
    "<tr>
    <td>".$info[0]."</td>
    <td>".$info[1]."</td>
    <td>".$info[2]."</td>
    <td>".$info[3]."</td>
    <td>".$info[4]."</td>
    <td><a href="."update_form.php?id=".$info[0].">수정</a></td>
    <td><a href="."delete.php".">삭제</a></td>
    </tr>");
}

echo("
</table>");

mysqli_close($connect);

include('foot.php');

