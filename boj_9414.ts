const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iT: number = parseInt(input[0]);
let iLine: number = 1;

while (iT-- > 0) {
  let arrNum: number[] = [];
  while (true) {
    let iNum: number = parseInt(input[iLine++]);
    if (iNum === 0) {
      break;
    }
    arrNum.push(iNum);
  }

  arrNum.sort((o1: number, o2: number): number => {
    return o2 - o1;
  });

  let iSum: number = 0;
  let iSize = arrNum.length;

  for (let i = 0; i < iSize; ++i) {
    let iCost = 2;
    for (let j = 0; j <= i; ++j) {
      iCost *= arrNum[i];
      if (iCost >= 5000001) {
        iCost = 5000001;
      }
    }
    iSum += iCost;
  }
  if (iSum >= 5000001) {
    console.log("Too expensive");
  }
  else {
    console.log(iSum);
  }
}
