import React, { useState } from 'react';
import './Calculator.css'; 

function Calculator() {
  const [num1, setNum1] = useState('');
  const [num2, setNum2] = useState('');
  const [result, setResult] = useState('0');
  const [error, setError] = useState('');

  const calculate = (operator) => {
    setError('');
    const n1 = parseFloat(num1);
    const n2 = parseFloat(num2);

    if (isNaN(n1) || isNaN(n2)){
      setError('Please enter both numbers.');
      setResult('0');
      return;
    }

    let calculationResult;
    switch (operator) {
      case '+': calculationResult = n1 + n2; break;
      case '-': calculationResult = n1 - n2; break;
      case '*': calculationResult = n1 * n2; break;
      case '/': 
        if (n2 === 0) {
          setError('Cannot divide by zero!');
          setResult('0');
          return;
        }
        calculationResult = n1 / n2; 
        break;
      default: calculationResult = 0;
    }
    setResult(calculationResult.toString());
  };

  return (
  
    <div className='calculator-container'> 
      <h2>Calculator</h2>
      <input 
        type="number" 
        placeholder="Enter first number" 
        value={num1} 
        onChange={(e) => setNum1(e.target.value)} 
      />
      <input 
        type="number" 
        placeholder="Enter second number" 
        value={num2} 
        onChange={(e) => setNum2(e.target.value)} 
      />
      
      <div className='btn-group'>
        <button onClick={() => calculate('+')}>+</button>
        <button onClick={() => calculate('-')}>−</button>
        <button onClick={() => calculate('*')}>×</button>
        <button onClick={() => calculate('/')}>÷</button>
      </div>
      
      {error ? (
        <div className="error-display">{error}</div>
      ) : (
        <div className="result-display">Result: {result}</div>
      )}
    </div>
  );
}

export default Calculator;