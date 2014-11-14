<?php
/**
* 
*/
class Coordinates 
{
	
	function __construct()
	{
		// code ...
	}

	function getLatLong($address) {
 
	    $address = str_replace(' ', '+', $address);
	    $url = 'http://maps.googleapis.com/maps/api/geocode/json?address='.$address.'&sensor=false';
	 
	    $ch = curl_init();
	    curl_setopt($ch, CURLOPT_URL, $url);
	    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
	    $geoloc = curl_exec($ch);
	    
	    return $geoloc;
	    // $json = json_decode($geoloc);
	    // return array($json->results[0]->geometry->location->lat, $json->results[0]->geometry->location->lng);
 
	}
}


$cc = new Coordinates();
$cc->getLatLong($_GET["origin"]);

?>
