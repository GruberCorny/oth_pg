var express = require("express");

const PORT = 5000;

app = express();

app.get("/", function(req, res) {
    res.send("<h1>Hello! You requested the start page!</h1>");
});

app.get("/about", function(req, res) {
    res.send("<h1>Hello! You requested the about page!</h1>");
});

app.listen(PORT, function() {
    console.log(`Server running and listening on port ${PORT}`);
})