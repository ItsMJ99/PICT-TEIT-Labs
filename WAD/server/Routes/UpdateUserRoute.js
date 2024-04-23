import express from 'express';
import User from '../Models/UserModel.js';

const router = express.Router();

router.put("/:username", async (req, res) => {
  const { username } = req.params;
  const { email, password } = req.body;

  try {
    const user = await User.findOne({ username: username });

    if (!user) {
      return res.status(404).json({ error: 'User not found' });
    }
    user.email = email || user.email;
    user.password = password || user.password;

    const updatedUser = await user.save();

    res.json(updatedUser);
  } catch (err) {
    console.error('Error updating user:', err);
    res.status(500).json({ error: 'Internal server error' });
  }
});

export default router;
