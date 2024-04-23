// UserController.js

import User from '../Models/UserModel.js';

// Get user by id
export const getUserById = async (req, res) => {
    try {
        const id = req.params.id;
        console.log(`User id [${id}]`);

        const user = await User.findOne({ _id: id });

        if (user) {
            return res.status(200).send({
                body: user
            });
        } else {
            return res.status(404).send({
                body: "",
                message: `User does not exist [id=${id}]`
            });
        }
    } catch (error) {
        console.error('Error fetching user:', error);
        return res.status(500).send({
            body: "",
            message: `Error in fetching user\n${error}`
        });
    }
}

// Create a new user
export const createUser = async (req, res) => {
    try {
        const { username, email, password } = req.body;
        console.log(`User [username=${username}, email=${email}, password=${password}]`);

        const userFromDB = await User.findOne({ email: email });

        if (userFromDB) {
            return res.status(400).send({
                message: "User already exists"
            });
        } else {
            const newUser = new User({
                username,
                email,
                password
            });

            const user = await newUser.save();

            return res.status(201).send({
                body: user,
                message: `User created successfully`
            });
        }
    } catch (error) {
        console.error('Error creating user:', error);
        return res.status(500).send({
            body: "",
            message: `Error in creating user\n${error}`
        });
    }
}

// Update user by id
export const updateUser = async (req, res) => {
    try {
        const { id } = req.params;
        const { username, email, password } = req.body;
        console.log(`User [id=${id}, username=${username}, email=${email}, password=${password}]`);

        const updatedUser = await User.findByIdAndUpdate(id, { username, email, password }, { new: true });

        if (updatedUser) {
            return res.status(200).send({
                body: updatedUser,
                message: `User updated successfully`
            });
        } else {
            return res.status(404).send({
                body: "",
                message: `User not found`
            });
        }
    } catch (error) {
        console.error('Error updating user:', error);
        return res.status(500).send({
            body: "",
            message: `Error in updating user\n${error}`
        });
    }
}

// Delete user by id
export const deleteUser = async (req, res) => {
    try {
        const { id } = req.params;

        const deletedUser = await User.findByIdAndDelete(id);

        if (deletedUser) {
            return res.status(200).send({
                body: "",
                message: `User deleted successfully`
            });
        } else {
            return res.status(404).send({
                body: "",
                message: `User not found`
            });
        }
    } catch (error) {
        console.error('Error deleting user:', error);
        return res.status(500).send({
            body: "",
            message: `Error in deleting user\n${error}`
        });
    }
}
