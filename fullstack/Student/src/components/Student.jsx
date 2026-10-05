import { use, useState } from "react";
import "./Student.css";

function Student() {

  const [name, setName] = useState('');
  const [rollNo, setRollNo] = useState('');
  const [mark1, setMark1] = useState('');
  const [mark2, setMark2] = useState('');
  const [mark3, setMark3] = useState('');
  const [mark4, setMark4] = useState('');
  const [mark5, setMark5] = useState('');
  
  const [err, setErr] = useState('')
  const [show, setShow] = useState(false);
  const [total, setTotal] = useState(0);
  const [percentage, setPercentage] = useState(0);

  const showresult = () => {

    if(mark1 >100 || mark1 < 0 || mark2 > 100 || mark2 < 0 || mark3 > 100 || mark3 < 0 || 
        mark4 > 100 || mark4 < 0 || mark5 > 100 || mark5 < 0){

          setErr("Marks should be between 0 and 100");
          setShow(true);
    }else{

      const sum = Number(mark1) + Number(mark2) + Number(mark3) + Number(mark4) + Number(mark5);
      const percent = (sum / 500) * 100;
      setTotal(sum);
      setPercentage(percent);
      setShow(true);
    }

  };

  return (
    <div className="container">
      <div className="card">
        <h2 className="title">Student Result Calculator</h2>

        <input type="text" placeholder="Enter Student Name" value={name} onChange={(e) => setName(e.target.value)} className="input" />
        <input type="number" placeholder="Enter Roll no" value={rollNo} onChange={(e) => setRollNo(e.target.value)} className="input" />
        <input type="number" placeholder="Marks 1" value={mark1} onChange={(e) => setMark1(e.target.value)} className="input" />
        <input type="number" placeholder="Marks 2" value={mark2} onChange={(e) => setMark2(e.target.value)} className="input" />
        <input type="number" placeholder="Marks 3" value={mark3} onChange={(e) => setMark3(e.target.value)} className="input" />
        <input type="number" placeholder="Marks 4" value={mark4} onChange={(e) => setMark4(e.target.value)} className="input" />
        <input type="number" placeholder="Marks 5" value={mark5} onChange={(e) => setMark5(e.target.value)} className="input" />

        <div className="button-container">
          <button onClick={showresult} className="button">

            Calculate Result
          </button>
        </div>

        {show && (
          <div className="result-box">
            <h3 className="result-title">Result Summary</h3>
            <p className="result-text"><strong>Name:</strong> {name}</p>
            <p className="result-text"><strong>Roll No:</strong> {rollNo}</p>
            <p className="result-text"><strong>Total Marks:</strong> {total} / 500</p>
            <p className="result-text"><strong>Percentage:</strong> {percentage.toFixed(2)}%</p>
            <p>{err}</p>
          </div>
        )}
      </div>
    </div>
  );
}

export default Student;