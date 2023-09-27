const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

function IsExistSeven(iN) {
  while (iN > 0) {
    if (iN % 10 === 7) {
      return true;
    }
    iN = parseInt(iN / 10);
  }
  return false;
}

const IsDivideSeven = (iN) => {
  return (iN % 7 === 0 ? true : false);
}

const iN = Number(input[0]);

let iAns = 0;
if (IsExistSeven(iN)) {
  iAns += 2;
}
if (IsDivideSeven(iN)) {
  iAns += 1;
}

console.log(iAns);
