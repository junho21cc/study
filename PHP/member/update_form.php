<?php
include('head.php');

$id = $_GET['id'];
$sql = "SELECT * FROM member WHERE id=$id";
$result = mysqli_query($connect, $sql);
if ($info=mysqli_fetch_array($result)) {
    $name = $info['name'];
    $phone = $info['phone'];
    $gender = $info['gender'];
    $age = $info['age'];

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

?>
<form action="update.php" method="GET">
    <input type="hidden" name="id" value="<?php echo $id; ?>">
    이름: <input type="text" name="name" size="4" value="<?php echo $name; ?>"><br>
    전화번호: <input type="text" name="phone" size="13" value="<?php echo $phone; ?>"><br>
    성별: <input type="text" name="gender" value="<?php echo $gender; ?>"><br>
    나이: <input type="text" name="age" value="<?php echo $age; ?>"><br>
    <input type="submit" value ="수정">
<?php
include('foot.php');