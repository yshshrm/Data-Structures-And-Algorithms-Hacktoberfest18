/*author: rishav krishna(https://github.com/rishu22)*/
<?php  
function getip()
{

	if(!empty($_SERVER['HTTP_CLIENT_IP']))
	{
		$ip=$_SERVER['HTTP_CLIENT_IP'];
	}


	elseif(!empty($_SERVER['HTTP_X_FORWARDED_FOR']))
	{
		$ip=$SERVER['HTTP_X_FORWARDED_FOR'];
	}

	
	else
	{
		$ip=$SERVER['REMOTE_ADDR'];
	}
	return $ip;
}

?>