import express from 'express';
import User from '../Models/UserModel.js';

const router = express.Router();

router.delete("/", async (req, res) => {
  const { username } = req.body;

  try {
    const deletedUser = await User.findOneAndDelete({ username: username });

    if (!deletedUser) {
      return res.status(404).json({ error: 'User not found' });
    }

    res.json({ message: 'User deleted successfully' });
  } catch (err) {
    console.error('Error deleting user:', err);
    res.status(500).json({ error: 'Internal server error' });
  }
});

export default router;
