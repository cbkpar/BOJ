const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iT: number = parseInt(input[0]);
let iIndex: number = 1;
let strAns: string = "";

while (iT-- > 0) {
  let strWord: string = input[iIndex++];
  let iN: number = parseInt(input[iIndex++]);
  let iLen = strWord.length;
  let iCorrect: number = -1;
  let strTempAns: string = "";

  while (iN--) {
    let strTemp: string = input[iIndex++];
    let iCorrectCount: number = 0;
    for (let i = 0; i < iLen; ++i) {
      if (strWord[i] === strTemp[i]) {
        ++iCorrectCount;
      }
    }
    if (iCorrectCount > iCorrect) {
      iCorrect = iCorrectCount;
      strTempAns = strTemp;
    }
  }

  strAns += strTempAns + "\n";
}

console.log(strAns);
