<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
    <script type="text/javascript" src="jquery/jquery.min.js"></script>
    <script src="plotly.min.js"></script>
    <script
    src="https://code.jquery.com/jquery-2.1.4.js"
    integrity="sha256-siFczlgw4jULnUICcdm9gjQPZkw/YPDqhQ9+nAOScE4="
    crossorigin="anonymous"></script>
    <title>Tampilan Sensor Suhu dan Kelembaban Real Time</title>
    <script type="text/javascript">
    $(document).ready(function() {
    setInterval(function(){
    $("#refreshsensor1").load('refreshsensor1.php');
    }, 1000);
    });
    $(document).ready(function() {
    setInterval(function(){
    $("#refreshsensor2").load('refreshsensor2.php');
    }, 1000);
    });
    </script>
</head>
<body>
    <div class="container" style="width:500px; height:350px;">
    <h2>Sensor Suhu: <span id="refreshsensor1"></span></h2>
    <h2>Sensor Kelembaban:  <span id="refreshsensor2"></span></h2> 
    </div>
    <div class="navbar"><span>Real-Time Chart with Plotly.js</span></div>
    <h1 id="demo"></h1>
    <div class="wrapper">
        <div id="chart"></div>
        <script>
             function getData() {
                var x=document.getElementById("refreshsensor1").innerHTML;
                  return Math.floor(x);
              }  
            Plotly.plot('chart',[{
                y:[getData()],
                type:'line'
            }]);
            
            var cnt = 0;
            setInterval(function(){
                Plotly.extendTraces('chart',{ y:[[getData()]]}, [0]);
                cnt++;
                if(cnt > 500) {
                    Plotly.relayout('chart',{
                        xaxis: {
                            range: [cnt-500,cnt]
                        }
                    });
                }
            },1000
            );
        </script>
    </div>
</body>
</html>