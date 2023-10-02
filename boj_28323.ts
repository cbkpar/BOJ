const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iN: number = parseInt(input[0]);
let arrNum: number[] = input[1].split(' ').map((e: string) => parseInt(e));

let iAns = 1;
for (let i = 1; i < iN; ++i) {
  if (arrNum[i - 1] % 2 != arrNum[i] % 2) {
    ++iAns;
  }
}

console.log(iAns);
