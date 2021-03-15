<?php
include('head.php');
?>
<form action="input.php" method="GET">
    이름: <input type="text" name="name" size="4"><br>
    전화번호: <input type="text" name="phone" size="13"><br>
    성별: <input type="text" name="gender" ><br>
    나이: <input type="text" name="age" ><br>
    <input type="submit" value ="제출">
<?php
include('foot.php');