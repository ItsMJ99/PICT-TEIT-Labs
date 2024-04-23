import React from 'react';
import "./App.css";

export default function App() {
  return (
    <div>
      <nav>
        <h1 id='header'>Login Page</h1>
      </nav>
      <div className='form-container'>
      <form id='form'> 
      <p>Username</p>
      <input type='text' id='username'/>
      <p>Password</p>
      <input type='password' id='password'/>
      <br></br>
      <button id='login-btn' type='submit'>Login</button>
      <button id='login-btn' type='submit'>Registrationnp</button>
      </form>
      </div>
      <footer></footer>
    </div>
  )
}
