var express = require("express");
//required to parse the body of a post request
var bodyParser = require("body-parser");

var app = express();

var urlencodedParser = bodyParser.urlencoded({ extended: false });

//app configuration
//turn on serving static files (required for delivering css to client)
app.use(express.static("public"));
const PORT = 3000;

//setup template engine
app.set("views", "views");
app.set("view engine", "pug");

//define routes
app.get("/", function(request, response) {
   response.render("index"); 
});

app.post("/welcome", urlencodedParser, function(request, response) {
    response.render("welcome", {data: request.body});
});

//start server
app.listen(PORT, function() {
    console.log(`Hello form app running and listening on port ${PORT}`);
});