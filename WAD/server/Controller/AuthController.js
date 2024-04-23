import UserModel from "../Models/UserModel.js";
import bcrypt from "bcrypt";

//registering a new user
export const registerUser = async(req,res)=>{
    const { firstname, lastname, username, password} = req.body;

    const salt = await bcrypt.genSalt(10);
    const saltedPassword = await bcrypt.hash(password, salt);

    const newUser = new UserModel({firstname, lastname, username, password: saltedPassword});

    try{
        await newUser.save()
        res.status(200).json(newUser)
    }
    catch(e){
        res.status(500).json({message: e.message});
    }
};

// login user
export const loginUser = async(req,res)=>{
    const {username,password} = req.body;

    try{
        const user = await UserModel.findOne({username: username})
        if(user){
            const validity = await bcrypt.compare(password, user.password)
            validity? res.status(200).json(user): res.status(400).json("Wrong Password")
        }
        else{
            res.status(400).json("User Does not exist")
        }
    }
    catch(e){
        res.status(500).json({message: e.message});
    }
}