<?php



// Grab GETS AND PUT COOKIES with errors and debug info sent to global htmi
sterilizegets();
//sterilizeposts();
setallcookies();
$ALL_VARGS='me='.$me.'&u='.$u.'&to='.$to.'&from='.$from;
// end grab and put cookies


require '/Library/WebServer/Documents/code_green/sometools.php';




$htmi=$MAIL;
$htmi['code_green interface']=$htmi.$ERROR_.$ERROR_LOG_.$MODSsl.$c;
?>

<HTML><HEAD>
<//--?/ 

// *  ibus.h HTMI Stilus V 0.0.0.82b
// *  Created by J on 8/22/13.
// *  Copyright 2013 GLDBRS Ent. All rights reserved.
// *  processhtmi() is left the same for some server headers
// *  use skinhtmi() to skin htmi projects v4 not v6

--//>

<script language=javascript>
function other_alert(){window.somestuff='123'; alert(window.somestuff+window.otherstuff);}
function display_alert(){alert('Charduk Error Reporting');}
</script>
<script language=text/javascript>
c='

<?php


function debugging_nvram_generate()
{
//UPDATES THE GLOBAL HTMI DEBUG INFO
global $htmi;
//END GLOBAL DECLARE

$htmi['debug'].=show_ip();
$htmi['debug'].=show_cookies();



}

function show_ip(){$ip=$_SERVER['REMOTE_ADDR']; 
return "Your IP Address is $ip<br><a href='http://".$_SERVER['REMOTE_ADDR'].$_SERVER['PHP_SELF']."'>http://".$_SERVER['REMOTE_ADDR'].$_SERVER['PHP_SELF']."</a><br><br>";
}


	   

	   
	   
	   
	function output_skinned_htmi($html,$htmi_head,$ERROR_,$debug,$debug_ON,$ERROR_ON){
	   //ARRAY MUST BE PARSED (parsevar declared below) TO AVOID BUGS
	   parsevar($debug);
	   parsevar($ERROR_);
	   //parsevar($htmi['ERROR_']);
	   
	   //	include '/Library/WebServer/Documents/code_green/currentskin.php';
	   
	   $ibus=$html;
		$htmi.='\'</script>';
	   $htmi.=$htmi_head;
		$htmi.='</head><body bgcolor=';
	   $htmi.=$BACKGROUND_COLOR;
	   $htmi.='>';
	   $ERROR_PNG="<img src=http://127.0.0.1/code_orange/ko.png width=40px>";
	   if($ERROR_ON>0){$htmi.="<center><input type='Image' onclick='javascript: window.display_alert();' src='http://127.0.0.1/charduk/Castle.gif'><br></center>".$ERROR_PNG.' <u>CHARDUK ERROR REPORTING</u> <b>ON</b>: '.$ERROR_ON.' total errors.<br><br>'.$ERROR_.'<br><br>';}else{}
	   
	   $htmi.='<font face="Arial">';
	   $htmi.=$ibus;
	   $htmi.='</font>';
	   if($debug_ON>0){$htmi.='<br>Debugging ON:<br>'.$debug.'<br><br>';}else{}
	   
	   $htmi.='</body></html>';	
	   //FINAL ECHO WRITE!
	   echo $htmi;
	   }
	   
	   
	   
	   
	   
	   


function output_skinned_htmi2($html,$htmi_head,$ERROR_,$debug,$debug_ON,$ERROR_ON){
//ARRAY MUST BE PARSED (parsevar declared below) TO AVOID BUGS
	parsevar($debug);
	parsevar($ERROR_);
	//parsevar($htmi['ERROR_']);
	
//	include '/Library/WebServer/Documents/code_green/currentskin.php';

$ibus=$html;
$htmi.='"</script>';
$htmi.=$htmi_head;
$htmi.='</head><body bgcolor=';
$htmi.=$BACKGROUND_COLOR;
	$htmi.='>';
	$ERROR_PNG="<img src=http://127.0.0.1/code_orange/ko.png width=40px>";
	if($ERROR_ON>0){$htmi.="<center><img src=http://127.0.0.1/charduk/Castle.gif><br></center>".$ERROR_PNG.' <u>CHARDUK ERROR REPORTING</u> <b>ON</b>: '.$ERROR_ON.' total errors.<br><br>'.$ERROR_.'<br><br>';}else{}
	
$htmi.='<font face="Arial">';
$htmi.=$ibus;
$htmi.='</font>';
	if($debug_ON>0){$htmi.='<br>Debugging ON:<br>'.$debug.'<br><br>';}else{}
	
$htmi.='</body></html>';	
//FINAL ECHO WRITE!
echo $htmi;
}


function skinhtmi($htmi){
	
	include '../currentskin.php';
	$ibus=$htmi;
	$htmi.='<HTML><HEAD><HEAD><body bgcolor=';
	$htmi.=$LIGHTCOLOR1;
	$htmi.='><font face=Arial>';
	$htmi.=$ibus;
	$htmi.=print_r($ERROR_);
	$htmi.='</font></body></html>';
	return $htmi;
}

function processhtmi($htmi){
	$htmi=$MAIL;
	$ibus=$htmi;
	$htmi.='<HTML><HEAD><HEAD><body bgcolor=';
	$htmi.='><font face=Arial>';
	echo $ibus;
	print_r($ERROR_);
	$htmi.='</font></body></html>';
	return $htmi;
}





function build_debugbox($htmi,$ERROR_,$debug,$me,$to,$u,$from)
{
$htmi='<pre>'.allvargs_list($htmi,$ERROR_,$debug,$me,$to,$u,$from);
//read filenames and sizes
if ($handle = opendir('/Library/WebServer/Documents/code_green/user-'.$me.'/')) {
while (false !== ($file = readdir($handle))) {
if ($file != "." && $file != ".." && $file != ".DS_Store")
{$file='/Library/WebServer/Documents/code_green/user-'.$me.'/'.$file; $caches[]=array('name'=>$file,'time'=>filemtime($file),'size'=>filesize($file));}}closedir($handle);}

$newest=array_reverse($caches);
$htmi.='<pre>';
//$htmi.=print_r($newest);
$xxe=1;
$sizekb=0;
//throw each cache in an array
foreach($newest as $cache){
if($sizekb<2000000){$xxe++;
$sizekb=($sizekb+$cache[size]);
$htmi.=$cache[name].'<br>';
$htmi.=$cache[size].'<br>';
$Arr_of_jsons[]=unserialize(file_get_contents($cache[name], true));}
}
$htmi.='</pre><br><br>';
return $htmi;
}



function login($email,$password,$ERROR_,$debug){
//$debug[$all_]=>$debug['<b>Ibus: </b>];
$debug=print_r($debug);
//open user file based on email
//check password against user file
//return password correct or password not correct
//display Someone who's IP is : xx.xx.xx.xx used email@address.com to login with
//a CORRECT/WRONG password on "DATE_" at "TIME_" and it was their 1'st,2nd,3rd,4th,5th and final login attempt.

$number=1;
if ($number=0){
$LOGIN_STATUS_MESSAGE='PASSWORD CORRECT WELCOME HOME <br>';
}

if ($number=1){
$LOGIN_STATUS_MESSAGE='PASSWORD INCORRECT PLEASE CORRECT YOUR ENTRY AND TRY AGAIN <br>';
}

if($ERROR_ON=1 && $debug_ON=1){
$debug['<b>Status: <b>']='Error Reporting is <b>ON</b>,<br> Debugging Console is <b>ON</b><br>';
return $LOGIN_STATUS_MESSAGE.$email.$password.$ERROR_.$debug;}else{return $LOGIN_STATUS_MESSAGE.$email.$password.$debug;}

}



function parsevar($htmi){
	//PARSE A VARIABLE ARRAY TO CONTAIN SERIAL ARGUMENTS AFTER PASSSING TO FUNCTION
	foreach ($htmi as &$entry) {
		$entry = $entry;
	}
	// $debug is now array(arg,arg,arg)
	unset($entry); // break the reference with the last element
}





function sterilizegets(){
	global $ERROR_ON;
	$ERROR_COUNT=0;
	$Blocked=0;
	//THIS FUNCTION REQUIRES GLOBAL VARIABLE ACCESS IT OPERATES ON THE ME,TO,U,FROM
	global $htmi;
	global $me;
	global $to;
	global $u;
	global $from;
	//END REQUIRED GLOBAL DECLARE
	
	if(is_numeric($_GET['me'])){$me=intval($_GET['me']);}else{$Blocked++; $ERROR_['CODE GREEN'].= "me blocked (not numeric)<br>";}
	if(is_numeric($_GET['to'])){$to=intval($_GET['to']);}else{$Blocked++; $ERROR_['CODE GREEN'].= "to blocked (not numeric)<br>";}
	if(is_numeric($_GET['u'])){$u=intval($_GET['u']);}else{$Blocked++; $ERROR_['CODE GREEN'].= "u blocked (not numeric)<br>";}
	if(is_numeric($_GET['from'])){$from=intval($_GET['from']);}else{$Blocked++; $ERROR_['CODE GREEN'].= "from blocked (not numeric)<br>";}
	
	$debug= $Blocked." Variables Blocked: (Not Numeric) or Not in URL<br>";
	$ERROR_['CODE ORANGE'].=$debug;
	
//	DEPRECIATED
//	$me=intval($_GET['me']);
//	$to=intval($_GET['to']);
//	$u=intval($_GET['u']);
//	$from=intval($_GET['from']);
	
	//ERROR_COUNT must INCREMENT in the Required Variables (such as ME below)
	if(intval($me)!=0){$htmi['debug'].="Me = ".$me."<br>";}else{$ERROR_COUNT++; $ERROR_['CODE ORANGE'].= "<u>ME Variable Not Set</u><br>";}
	if(intval($to)!=0){$htmi['debug'].="To = ".$to."<br>";}else{$ERROR_['CODE ORANGE'].= "TO Variable Not Set<br>";}
	if(intval($u)!=0){$htmi['debug'].="U = ".$u."<br>";}else{$ERROR_['CODE ORANGE'].= "U Variable Not Set<br>";}
	if(intval($from)!=0){$htmi['debug'].="From = ".$from."<br>";}else{$ERROR_['CODE ORANGE'].= "FROM Variable Not Set<br>";}
	
	
	//inside the function the errors are counted above, then added to the global error_on count
	$ERROR_ON=$ERROR_ON+$ERROR_COUNT;
	if ($ERROR_COUNT>0){
		$htmi['ERROR_'].=$ERROR_COUNT." Error(s) in sterilizegets() : CODE ORANGE: <br>".$ERROR_['CODE ORANGE'].'<br>';
		return $htmi['ERROR_'];}else{
			$debug.='sterilizegets() : <b>CODE GREEN No Errors</b><br><br>';
			$htmi['debug'].=$debug; 
			
			return $htmi;}
	
}





function checkflag($ERROR_ON){
	//FUNCTION CHECKS THE ERROR_ON VARIABLE SET ON EACH PHP PAGE FOR MANUAL ON (TO TEST CHARDUK)
	global $debug;
	$ERROR_COUNT=$ERROR_ON;
	
	if(intval($ERROR_COUNT)>0){$ERROR_['CODE_ORANGE'].= $ERROR_COUNT." Error On Flag Manually Set<br>";
		return $ERROR_['CODE_ORANGE'];
	}else{$debug.="(ERROR_ON=".$ERROR_COUNT.") charduk test flag is turned off: ".$_SERVER['PHP_SELF']."<br>";}
}

function show_cookies(){
	//THIS FUNCTION RETURNS INTEGER VALUE OF THE ALLOWED COOKIES 
	global $htmi;
	$htmi['debug'].= '<b>me</b> cookie is: '.intval($_COOKIE['me']).'<br>';
	$htmi['debug'].= '<b>to</b> cookie is: '.intval($_COOKIE['to']).'<br>';
	$htmi['debug'].= '<b>u</b> cookie is: '.intval($_COOKIE['u']).'<br>';
	$htmi['debug'].= '<b>from</b> cookie is: '.intval($_COOKIE['from']).'<br>';
	unset($htmi);
}

function setallcookies(){
	//THIS FUNCTION SETS ALL ID VARIABLES IN GET TO COOKIE;
	//THIS FUNCTION REQUIRES GLOBAL VARIABLE ACCESS IT OPERATES ON THE ME,TO,U,FROM
	global $htmi;
	global $me;
	global $to;
	global $u;
	global $from;
	//END REQUIRED GLOBAL DECLARE
	
	
	
	//set cookies
	$htmi['debug'].="setting cookie 'me' to ".$me."<br>";
	setcookie("me", $me, time()+3600);  /* expire in 1 hour */
	$htmi['debug'].="setting cookie 'to' to ".$to."<br>";
	setcookie("to", $to, time()+3600);  /* expire in 1 hour */	
	$htmi['debug'].="setting cookie 'u' to ".$u."<br>";
	setcookie("u", $u, time()+3600);  /* expire in 1 hour */
	$htmi['debug'].="setting cookie 'from' to ".$from."<br>";
	setcookie("from", $from, time()+3600);  /* expire in 1 hour */
}


//ADITIONAL INCLUDES HERE
include '/Library/WebServer/Documents/code_green/DIRMAP.php';


?>

