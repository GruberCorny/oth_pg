var express = require("express");

const PORT = 3000;

app = express();

//setup template engine
app.set("views", "views");
app.set("view engine", "pug");

app.get("/", function(req, res) {
    var currentDate = new Date(); 
    var time = `${currentDate.getHours()}:${currentDate.getMinutes()}:${currentDate.getSeconds()}`;
    
    var day = currentDate.getDate();
    var month = currentDate.getMonth()+1; //January is 0!
    var year = currentDate.getFullYear();
    var date = `${day}.${month}.${year}`;
    
    res.render("index", {date: date, time: time});
});

app.listen(PORT, function() {
    console.log(`Server running and listening on port ${PORT}`);
})