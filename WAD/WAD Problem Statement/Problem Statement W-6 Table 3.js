createTable = (t1, t2) => {
    if (t1.trim() === "" || t2.trim() === "") {
        alert('Please fill both the input fields');
    } else {
        let t1Array = t1.split('#').map(Number);
        let t1Row = t1Array[0];
        let t1Col = t1Array[1];
        let t1Start = t1Array[2];
        let t1A = new Array(t1Row);

        for (let i = 0; i < t1Row; i++) {
            t1A[i] = new Array(t1Col);
        }

        let table1 = "<table id='table1'>";
        for (let i = 0; i < t1Row; i++) {
            table1 += "<tr>"
            for (let j = 0; j < t1Col; j++) {
                table1 += `<td>${t1Start}</td>`;
                t1A[i][j] = t1Start;
                if (i + 1 === t1Row && j + 1 === t1Col) break;
                t1Start = prompt(`Enter table 1's ${(j + 1) + (t1Col * i)} value`);
            }
            table1 += "</tr>";
        }
        table1 += "</table>";
        document.getElementById('table1-container').innerHTML = table1;

        let t2Array = t2.split('#').map(Number);
        let t2Row = t2Array[0];
        let t2Col = t2Array[1];
        let t2Start = t2Array[2];
        let t2A = new Array(t2Row);

        for (let i = 0; i < t2Row; i++) {
            t2A[i] = new Array(t2Col);
        }

        let table2 = "<table id='table2'>";
        for (let i = 0; i < t2Row; i++) {
            table2 += "<tr>"
            for (let j = 0; j < t2Col; j++) {
                table2 += `<td>${t2Start}</td>`;
                t2A[i][j] = t2Start;
                if (i + 1 === t2Row && j + 1 === t2Col) break;
                t2Start = prompt(`Enter table 2's ${(j + 1) + (t2Col * i)} value`);
            }
            table2 += "</tr>";
        }
        table2 += "</table>";
        document.getElementById('table2-container').innerHTML = table2;

        let t3Row = Math.max(t1Row, t2Row);
        let t3Col = Math.max(t1Col, t2Col);
        let table3="<table id='table3'>";
        for(let i = 0 ; i < t3Row ; i++ ){
            table3+='<tr>';
            for(let j = 0 ; j < t3Col ; j++ ){
                let value;
                if(t1A[i] && t2A[i] && t1A[i][j]===t2A[i][j]){
                    value=t1A[i][j];
                    classvalue = 'same-value';
                }
                else {
                    value = ( t1A[i] && t1A[i][j] || 1) * ( t2A[i] && t2A[i][j] || 1);
                    classvalue = 'different-value';
                }
                table3+=`<td class=${classvalue}>${value}</td>`
            }
            table3+='</tr>';
        }
        table3+='</table>';
        document.getElementById('table3-container').innerHTML=table3;
    }
}
