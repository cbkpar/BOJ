const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

const iN: number = parseInt(input[0]);
const ArrNumber: number[] = input[1].split(' ').map((e: string) => parseInt(e));

let iAns: number = 1000000000;
for (let i = 0; i < iN; ++i) {
  if (iAns > ArrNumber[i]) {
    iAns = ArrNumber[i];
  }
}

console.log('%d.00', iAns);
