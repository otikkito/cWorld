<html>
<!-- https://codular.com/php-mysqli -->
<!-- https://www.w3schools.com/php/php_ref_mysqli.asp -->
<!-- https://www.websiteout.net/  -->
<!-- databases setup:~https://github.com/otikkito/cWorld/blob/master/databases/notes.txt -->
<head>
<title>Kito Joseph's website</title>
</head>	
<center><h1>Welcome to Kito Marid Joseph's website</h1></center>
	<p>Please build out this learning website. This site is always under construction. Current location is Raleigh, NC. I am a <a href=https://www.ece.ncsu.edu/ugrad/cpe/> computer</a> and <a href=https://www.ece.ncsu.edu/ugrad/ee/>electrical</a> engineer that graduated from North Carolina State University in 2009 and I am looking for work. Make sure that you site your sources.</p><br>
<?php
echo shell_exec('uptime -p');
?>
<br><br>
<!-- site for hit counter https://www.thoughtco.com/web-page-hit-counter-2693831 -->
<!-- mysqli documentation: https://www.php.net/manual/en/book.mysqli.php -->
<?php

//php version of server: 7.2.24 
$db = new mysqli('localhost', 'root', 'redhat', 'kitosdb');

if($db->connect_errno > 0){
    		die('Unable to connect to database [' . $db->connect_error . ']');
}

$sql = "UPDATE counter SET counter = counter + 1";

if(!$result = $db->query($sql)){
	    die('There was an error running the query [' . $db->error . ']');
}

$sql = "SELECT * from counter";

if(!$result = $db->query($sql)){
            die('There was an error running the query [' . $db->error . ']');
}
echo "Hits using mariadb: ";
//echo  $result->num_rows;
$row = $result->fetch_array();
echo $row['counter'];
//echo $result[1] ;

$result->free();
$db->close();
?>

<br>
<a href="https://bugzilla.redhat.com/">Red Hat Bugzilla.</a><br><br><br>
<?php
echo "Today's date is: " . date("m/d/Y") . "<br>";
?>
<p><a href="https://github.com/otikkito/cWorld/blob/master/databases/notes.txt">Code for this page</a<br>
<p><a href="https://www.worldofmolecules.com/antioxidants/vitaminc.htm">Vitamin C</a></p>
<div data-iframe-width="150" data-iframe-height="270" data-share-badge-id="8419f706-1f58-466b-9349-7d419b16d7dc" data-share-badge-host="https://www.youracclaim.com"></div><script type="text/javascript" async src="//cdn.youracclaim.com/assets/utilities/embed.js"></script>
<div data-iframe-width="150" data-iframe-height="270" data-share-badge-id="4e254be8-ddf6-4050-a4cc-fb995c2b1c1b" data-share-badge-host="https://www.youracclaim.com"></div><script type="text/javascript" async src="//cdn.youracclaim.com/assets/utilities/embed.js"></script>
<div data-iframe-width="150" data-iframe-height="270" data-share-badge-id="12cf5260-bece-4239-bc29-91622f6b3203" data-share-badge-host="https://www.youracclaim.com"></div><script type="text/javascript" async src="//cdn.youracclaim.com/assets/utilities/embed.js"></script>

<!-- hitwebcounter Code START -->
<a href="https://www.hitwebcounter.com" target="_blank">
<img src="https://hitwebcounter.com/counter/counter.php?page=7439199&style=0001&nbdigits=5&type=page&initCount=0" title="Web Counter" Alt="counter free"   border="0" >
</a>                 

<script type="text/javascript" src="//counter.websiteout.net/js/22/0/0/1"></script>	
<p> Also check out <a href="http://www.kjoseph-it.com">www.kjoseph-it.com</a> , <a href="http://www.linkedin.com/in/kitojoseph">www.linkedin.com/in/kitojoseph</a></p>
<p>Please dontate to keep these sites alive.<form action="https://www.paypal.com/cgi-bin/webscr" method="post" target="_top">
<input type="hidden" name="cmd" value="_donations" />
<input type="hidden" name="business" value="T84TGJBVD5WUN" />
<input type="hidden" name="currency_code" value="USD" />
<input type="image" src="https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif" border="0" name="submit" title="PayPal - The safer, easier way to pay online!" alt="Donate with PayPal button" />
<img alt="" border="0" src="https://www.paypal.com/en_US/i/scr/pixel.gif" width="1" height="1" />
</form>
	<?php

	$db = new mysqli('localhost', 'root', 'redhat', 'kitosdb');

	if($db->connect_errno > 0){
    		die('Unable to connect to database [' . $db->connect_error . ']');
	}

	$sql = "SELECT * from personlist where lname like 'ra%';";	
	
	if(!$result = $db->query($sql)){
	    die('There was an error running the query [' . $db->error . ']');
	}
	
	while($row = $result->fetch_assoc()){
		printf ("%s %s\n", $row["fname"], $row["lname"]);
	echo '<br>';
	}
	
	$result->free();

	phpinfo();
	?>
</html>
