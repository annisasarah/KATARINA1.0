<?php 

$connect=mysqli_connect("localhost","root","","datasensor");

$sql=mysqli_query($connect,"SELECT * FROM sensorlembab");
$data = mysqli_fetch_assoc($sql);
$nilai = $data["nilai"];

echo $nilai;
?>