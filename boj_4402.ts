const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

const iN: number = input.length;
let strAns: string = "";

for (let i = 0; i < iN; ++i) {
  const iLen: number = input[i].length;
  let iBefore: number = -1;
  for (let j = 0; j < iLen; ++j) {
    switch (input[i][j]) {
      case 'B':
      case 'F':
      case 'P':
      case 'V':
        if (iBefore !== 1) {
          strAns += "1";
          iBefore = 1;
        }
        break;
      case 'C':
      case 'G':
      case 'J':
      case 'K':
      case 'Q':
      case 'S':
      case 'X':
      case 'Z':
        if (iBefore !== 2) {
          strAns += "2";
          iBefore = 2;
        }
        break;
      case 'D':
      case 'T':
        if (iBefore !== 3) {
          strAns += "3";
          iBefore = 3;
        }
        break;
      case 'L':
        if (iBefore !== 4) {
          strAns += "4";
          iBefore = 4;
        }
        break;
      case 'M':
      case 'N':
        if (iBefore !== 5) {
          strAns += "5";
          iBefore = 5;
        }
        break;
      case 'R':
        if (iBefore !== 6) {
          strAns += "6";
          iBefore = 6;
        }
        break;
      default:
        iBefore = 0;
        break;
    }
  }
  strAns += "\n";
}

console.log(strAns);
