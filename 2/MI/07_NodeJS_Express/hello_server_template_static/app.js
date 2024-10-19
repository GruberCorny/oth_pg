var express = require("express");

const PORT = 3000;

app = express();

//turn on serving static files (required for delivering css to client)
app.use(express.static('public'));

//setup template engine
app.set("views", "views");
app.set("view engine", "pug");

app.get("/", function(req, res) {
    res.render("index");
});

app.listen(PORT, function() {
    console.log(`Server running and listening on port ${PORT}`);
});