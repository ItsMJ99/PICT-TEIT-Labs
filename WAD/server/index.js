import express from "express";
import bodyParser from "body-parser";
import mongoose from "mongoose";
import dotenv from "dotenv";
import AuthRoute from "./Routes/AuthRoute.js";
import UserRoute from "./Routes/UserRoute.js";
import UpdateUserRoute from "./Routes/UpdateUserRoute.js";
import DeleteUserRoute from "./Routes/DeleteUserRoute.js"; 

const app = express();

app.use(bodyParser.json({ limit: '30mb', extended: true }));
app.use(bodyParser.urlencoded({ limit: '30mb', extended: true }));

dotenv.config();

mongoose.connect(process.env.MONGO_DB, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => {
    app.listen(process.env.PORT, () => {
      console.log(`Connected to MongoDB and Listening at port ${process.env.PORT}`);
    });
  })
  .catch((error) => {
    console.error("Error while Connecting to Database:", error);
  });

// Route usage
app.use('/auth', AuthRoute);
app.use('/user', UserRoute);
app.use('/updateUser', UpdateUserRoute);
app.use('/deleteUser', DeleteUserRoute); 

export default app;
