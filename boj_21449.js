const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let inputNM = input[0].split(' ');

let iN = Number(inputNM[0]);
let iK = Number(inputNM[1]);

let arrNum = input[1].split(' ').map((e) => parseInt(e));
let iSum = 0;
for (let i = 0; i < iN; ++i) {
  while (iK % (++arrNum[i]) == 0) {
    ++iSum;
  }
}

console.log(iSum);
