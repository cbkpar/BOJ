const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

const iN = Number(input[0]);
const arrNum = input[1].split(' ').map((e) => parseInt(e));

let iSum = 1;
let iBefore = arrNum[0];
let bIncrease = true;

for (let i = 1; i < iN; ++i) {
  if (iBefore > arrNum[i]) {
    if (bIncrease) {
      ++iSum;
      bIncrease = false;
    }
  }
  else if (iBefore < arrNum[i]) {
    if (!bIncrease) {
      ++iSum;
      bIncrease = true;
    }
  }
  iBefore = arrNum[i];
}

console.log(iSum);
