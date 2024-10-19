var express = require("express");

const PORT = 3000;

app = express();


app.get("/", function(req, res) {
    var currentDate = new Date(); 
    var time = `${currentDate.getHours()}:${currentDate.getMinutes()}:${currentDate.getSeconds()}`;
    
    var day = currentDate.getDate();
    var month = currentDate.getMonth()+1; //January is 0!
    var year = currentDate.getFullYear();
    var date = `${day}.${month}.${year}`;
    
    res.send(`<table><tr><th>Time</th><th>Date</th></tr><tr><td>${time}</td><td>${date}</td></tr></table>`);
});

app.listen(PORT, function() {
    console.log(`Server running and listening on port ${PORT}`);
})