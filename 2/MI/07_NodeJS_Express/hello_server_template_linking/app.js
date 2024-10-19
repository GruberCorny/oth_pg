var express = require("express");

const PORT = 3000;

app = express();

//setup template engine
app.set("views", "views");
app.set("view engine", "pug");

app.get("/", function(req, res) {
   res.render("index");
});

app.get("/about", function(req, res) {
   res.render("about");
});

app.listen(PORT, function() {
    console.log(`Server running and listening on port ${PORT}`);
})