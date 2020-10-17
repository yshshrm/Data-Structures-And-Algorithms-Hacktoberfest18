<html>
<head>
<title>linear search</title>
</head>
<body>
<?php 

    function linear_search($arr,$k)
    {
        $n=count($arr);
        for($i=0;$i<$n;$i++)
        {
            if($arr[$i]==$k)
            {
                return $i+1;
                echo "<script>alert('Index of ".$k." is ".$i+1 ."')</script>";
            }
        }
        return -1;
        echo "<script>alert('Element not found!')</script>";
    }

?>
</body>
</html>
