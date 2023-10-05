const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iN: number = parseInt(input[0]);

let arrLeft: number[] = [];
let arrRight: number[] = [];

for (let i = 1; i <= iN; ++i) {
  let arrNum: number[] = input[i].split(' ').map((e: string) => parseInt(e));
  if (arrNum[1] === 0) {
    arrLeft.push(arrNum[0]);
  }
  else {
    arrRight.push(arrNum[0]);
  }
}

let iTime = 0;
let iLeft: number = 0;
let iRight: number = 0;
let iLeftSize: number = arrLeft.length;
let iRightSize: number = arrRight.length;
let iDir: number = -1;

while (true) {
  if (iLeft === iLeftSize && iRight === iRightSize) {
    break;
  }

  if (iLeft < iLeftSize && iRight < iRightSize) {
    if (arrLeft[iLeft] < arrRight[iRight]) {
      iTime = Math.max(iTime + (iDir === 1 ? 10 : 0), arrLeft[iLeft] + 10);
      ++iLeft;
      iDir = 0;

      while (iLeft < iLeftSize && arrLeft[iLeft] < iTime) {
        iTime = Math.max(iTime, arrLeft[iLeft] + 10);
        ++iLeft;
      }
    }
    else {
      iTime = Math.max(iTime + (iDir === 0 ? 10 : 0), arrRight[iRight] + 10);
      ++iRight;
      iDir = 1;

      while (iRight < iRightSize && arrRight[iRight] < iTime) {
        iTime = Math.max(iTime, arrRight[iRight] + 10);
        ++iRight;
      }
    }
  }
  else if (iLeft < iLeftSize) {
    iTime = Math.max(iTime + (iDir === 1 ? 10 : 0), arrLeft[iLeft] + 10);
    ++iLeft;
    iDir = 0;
  }
  else if (iRight < iRightSize) {
    iTime = Math.max(iTime + (iDir === 0 ? 10 : 0), arrRight[iRight] + 10);
    ++iRight;
    iDir = 1;
  }
}

console.log(iTime);
