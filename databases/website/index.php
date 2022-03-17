<html>
<!-- https://codular.com/php-mysqli -->
<!-- https://www.w3schools.com/php/php_ref_mysqli.asp -->
<!-- Database setup https://github.com/otikkito/cWorld/blob/master/databases/notes.txt  -->
<!-- Apache tutorial: https://www.guru99.com/apache.html -->
<!-- To get ip 4 address:#curl -4 icanhazip.com -->
<!-- Certificate Authority: https://letsencrypt.org/ -->	
<head>
<title>Kito Joseph's website</title>
</head>
<center><h1>Welcome to Kito Marid Joseph's website</h1></center><br>
<center>Last updated 1/13/22</center><br>
<!-- My isp is Spectrum -->
<br>
<p>Would you please build out this learning website? This site is always under construction. The current location of me and this website is Cary, NC, zip 27518. I am a <a href=https://www.ece.ncsu.edu/ugrad/cpe/> computer</a> and <a href=https://www.ece.ncsu.edu/ugrad/ee/>electrical</a> engineer that graduated from North Carolina State University (an accredited university) in 2009, and I am looking for job references. So make sure that you cite your sources and stay in practice. I am also looking to make new friends on Facebook. But if we connect, keep it clean.</p><br>
<a href="/Docs/Computer-Engineering-BS-14CPEBS.pdf">Computer and Electrical Engineering Curriculum</a>
<p>Possible jobs that are coming to Durham, NC which I hope I can land one of them.
<a href="https://abc11.com/business/google-to-create-hub-in-durham-add-1000+-jobs/10428545/">Google Jobs</a></p>
<?php
echo shell_exec('uptime -p'); 
?>
<br>
<?php
echo php_uname(a);
?>
<br>
<?php
system('cat /etc/redhat-release');
?>
<br>
My public ipv4 address:
<?php
system('curl -4 icanhazip.com');
?>
<br>
My public ipv6 address:
<?php
system('curl icanhazip.com');
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
<a href="https://bugzilla.redhat.com/">Red Hat Bugzilla.</a>&nbsp;<a href="https://access.redhat.com/">Red Hat Linux knowledge base</a>&nbsp;<a href="https://access.redhat.com/labs/rhcb/">Red Hat code browser</a>&nbsp;<a href="https://www.redhat.com/en/store">Red Hat store</a><br><br><br>
<a href="/Docs/KitoJosephResumeMCC.pdf">Kito's resume</a><br><a href="/Docs/discharge-list.pdf">Military benefits</a><br>
<a href="/workpics">Work-Datacenter-pictures</a>&nbsp;<a href="/botanicgarden">Juniper-level-botanic-garden-pictures</a>
<a href="/biltmore-estate">Biltmore-Estate-pictures</a> <br><br>
<?php
echo "Today's date is: " . date("m/d/Y") . "<br>";
?>
<p><a href="https://github.com/otikkito/cWorld/blob/master/databases/website/index.php">Code for this page</a<br>
<p><a href="https://www.worldofmolecules.com/antioxidants/vitaminc.htm">Vitamin C</a></p>
<div data-iframe-width="150" data-iframe-height="270" data-share-badge-id="8419f706-1f58-466b-9349-7d419b16d7dc" data-share-badge-host="https://www.youracclaim.com"></div><script type="text/javascript" async src="//cdn.youracclaim.com/assets/utilities/embed.js"></script>
<div data-iframe-width="150" data-iframe-height="270" data-share-badge-id="4e254be8-ddf6-4050-a4cc-fb995c2b1c1b" data-share-badge-host="https://www.youracclaim.com"></div><script type="text/javascript" async src="//cdn.youracclaim.com/assets/utilities/embed.js"></script>
<div data-iframe-width="150" data-iframe-height="270" data-share-badge-id="12cf5260-bece-4239-bc29-91622f6b3203" data-share-badge-host="https://www.youracclaim.com"></div><script type="text/javascript" async src="//cdn.youracclaim.com/assets/utilities/embed.js"></script>
<div data-iframe-width="150" data-iframe-height="270" data-share-badge-id="ee78551e-3122-4b50-8d75-31fb6f9278aa" data-share-badge-host="https://www.youracclaim.com"></div><script type="text/javascript" async src="//cdn.youracclaim.com/assets/utilities/embed.js"></script>
<!-- hitwebcounter Code START -->
<a href="https://www.hitwebcounter.com" target="_blank">
<img src="https://hitwebcounter.com/counter/counter.php?page=7439199&style=0001&nbdigits=5&type=page&initCount=0" title="Web Counter" Alt="counter free"   border="0" >
</a>                 

<script type="text/javascript" src="//counter.websiteout.net/js/22/0/0/1"></script>	
<p> Also check out <a href="http://www.kjoseph-it.com">www.kjoseph-it.com</a> , <a href="http://www.linkedin.com/in/kitojoseph">www.linkedin.com/in/kitojoseph</a>, <a href="http://www.ganssle.com/"> Embedded Systems</a></p>
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

	$sql = "SELECT * from personlist where lname like 'ro%';";	
	
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
<center><a href="https://www.kjoseph-it.com/">Kito Joseph's personal website</a></center>
</html>
