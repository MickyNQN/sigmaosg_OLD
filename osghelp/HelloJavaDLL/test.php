<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title></title>
    <meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
	<script type="text/javascript" src="https://www.google.com/jsapi"></script>
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.0/jquery.min.js"></script>
	<script src="//ajax.googleapis.com/ajax/libs/jqueryui/1.10.0/jquery-ui.min.js"></script>

	<script type="text/javascript">
		/*
		$(function() {
		});
		*/
	</script>
	
	<style>
	</style>

  </head>
  <body>
	<p>The purpose of this code is to load a dll using java so the c++ dll can run in a browser</p>
  <?php
	var_dump( $_REQUEST );
  ?>
	<!--
	<embed src="test.class" width="512" height="512" type="application/x-java-applet;version=1.6?"></embed>
	<APPLET CODE="test.class" width="512" height="512"></APPLET>
	-->
  <applet code="test.class" width="512" height="512">
	no support for java
  </applet>
</html>