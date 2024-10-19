<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8" />
    <title>Message received successful</title>
    <link rel="stylesheet" href="css/form_demo.css">
</head>

<body>
    <h1>Thank you for your message!</h1>
    
    <?php 
        if(postDataReceived()) {
            printPostData();
        } else {
            echo "<p>Error, no message received, please click <a href='index.html'>here</a> if you want to get in touch with us</p>";
        }
    ?>

</body>

</html>

<?php
    function postDataReceived() {
        if (isset($_POST["name"]) || isset($_POST["mail_address"]) || isset($_POST["message"])) {
            return true;
        } else {
            return false;
        }
    }
                  
    function printPostData() {
        echo "<p>Name: ".$_POST["name"]."</p>";
        echo "<p>E-Mail: ".$_POST["mail_address"]."</p>";
        echo "<p>Message: ".$_POST["message"]."</p>";
    }

?>