const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split(' ');

let iN = Number(input[0]);
let iK = Number(input[1]);

const ArrVisited = Array.from({ length: iN }, () => false);
let iSum = 0;
let iNow = -1;

while (true) {
  iNow = (iNow + iK) % iN;
  if (ArrVisited[iNow]) {
    break;
  }
  ArrVisited[iNow] = true;
  ++iSum;
}

console.log(iN - iSum);
