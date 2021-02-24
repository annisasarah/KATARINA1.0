<?php 
$connect=mysqli_connect("localhost","root","","datasensor");

$nilaisuhu = $_GET["sensorsuhu"];
$nilailembab=$_GET["sensorlembab"];

mysqli_query($connect,"update sensorsuhu set nilai='$nilaisuhu'");
mysqli_query($connect,"update sensorlembab set nilai='$nilailembab'");
?>