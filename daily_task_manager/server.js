const express = require("express");
const app = express();
const mongoose = require("mongoose");

mongoose.connect("mongodb://localhost:27017/taskdb");

app.use(express.json());

app.post("/login", (req, res) => {
  // handle authentication
});

app.get("/tasks", (req, res) => {
  // return tasks
});

app.listen(3000, () => console.log("Server running on port 3000"));