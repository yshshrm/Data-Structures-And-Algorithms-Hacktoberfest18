<?php

function Cipher($ch, $key){
	if (!ctype_alpha($ch))
		return $ch;

	$offset = ord(ctype_upper($ch) ? 'A' : 'a');
	return chr(fmod(((ord($ch) + $key) - $offset), 26) + $offset);
}

function Encipher($input, $key){
	$output = "";

	$inputArr = str_split($input);
	foreach ($inputArr as $ch)
		$output .= Cipher($ch, $key);

	return $output;
	echo 'output'; 
}


if(isset($_POST['SubmitButton'])){ //check if form was submitted
  $input = $_POST['inputText']; //get input text
  $key = $_POST['inputKey'];
  $finalString = Encipher($input,$key);
}  
?> 


<html>
<body>    
	<form action="" method="post">
		Enter the phrase to cipher
  		<input type="text" name="inputText"/>
  		<br>
  		Enter the key: 
  		<input type="text" name ="inputKey"/>
  		<?php echo "<br> result string: ".$finalString;?>
  		<input type="submit" name="SubmitButton"/>
	</form>    
</body>
</html>