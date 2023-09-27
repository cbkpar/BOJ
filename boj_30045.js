const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iCount = Number(input[0]);
let iAns = 0;

for (let i = 1; i <= iCount; ++i) {
  let iLen = input[i].length;
  let bFound = false;
  for (let j = 1; j < iLen; ++j) {
    if (input[i][j - 1] === '0' && input[i][j] === '1') {
      bFound = true;
    }
    if (input[i][j - 1] === 'O' && input[i][j] === 'I') {
      bFound = true;
    }
  }
  if (bFound) {
    ++iAns;
  }
}

console.log(iAns);
