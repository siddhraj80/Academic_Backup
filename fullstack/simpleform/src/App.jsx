import { use, useState } from 'react'
import heroImg from './assets/hero.png'
import reactLogo from './assets/react.svg'
import viteLogo from './assets/vite.svg'
import './App.css'

function App() {

  const [name, setName] = useState('');
  const [password, setPassword] = useState('');
  const [result, setResult] = useState('');
  const [resultcolor, setResultColor] = useState('');

  function login(){
    if(name == "siddhraj" && password == "0416"){

      setResultColor("green");
      setResult("login successfully!");
    }else{

      setResultColor("red");
      setResult("Incorrect username or password!");
    }
  
  }
  return (
    <>
    <div className='login'>
      <div className='login-details'>
        <h1>Login</h1><br/><br/>
        <input type="text" placeholder="Enter Username" onChange={e => (setName(e.target.value))} required/> <br/><br/>
        <input type="password" placeholder="Enter Password " onChange={e => (setPassword(e.target.value))} required/> <br/><br/>
        <button onClick={login}>Login</button>
        
      </div>
        <p style={ { background: resultcolor} }>{result}</p>
      </div>
    </>
  )
}

export default App
