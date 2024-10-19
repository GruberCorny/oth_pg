const express = require("express");
const dotenv = require("dotenv");

/* Reading global variables from config file */
dotenv.config();
const PORT = process.env.PORT;

app = express();

//turn on serving static files (required for delivering css to client)
app.use(express.static("public"));

//configure template engine
app.set("views", "views");
app.set("view engine", "pug");

app.get('/', (req, res) => {
    res.send("Welcome to OTHer.");
});

app.listen(PORT, function() {
  console.log(`App running and listening on port read from .env file ${PORT}`);
});
