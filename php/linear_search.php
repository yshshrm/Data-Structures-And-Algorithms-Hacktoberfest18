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
            }
        }
        return -1;
    }

?>
</body>
</html>