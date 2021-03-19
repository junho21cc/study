<?php
include('head.php');
include('common.php');

$id = $_GET['id'];

echo("id: $id<br>\n");

$sql = "SELECT * FROM member WHERE id=$id";

/** @var mysqli $connect */
$result = mysqli_query($connect, $sql);

if ($info=mysqli_fetch_array($result)) {
    $name = $info['name'];
    $phone = $info['phone'];
    $gender = $info['gender'];
    $age = $info['age'];
}

?>
<form action="update.php" method="GET">
    <input type="hidden" name="id" value="<?php echo($id); ?>">
    이름: <input type="text" name="name" size="4" value="<?php echo($name); ?>"><br>
    전화번호: <input type="text" name="phone" size="13" value="<?php echo($phone); ?>"><br>
    성별: <input type="radio" name="gender" value="M" <?php if($gender == 'M') echo('checked') ?>>남성
    <input type="radio" name="gender" value="W" <?php if($gender == 'W') echo('checked') ?>>여성<br>
    나이: <input type="text" name="age" value="<?php echo($age); ?>"><br>
    <input type="submit" value ="수정">
    <input type="button" value="취소" onClick="location.href='list.php'">
<?php
include('foot.php');
