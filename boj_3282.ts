const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let [iN, iG] = input[0].split(' ').map((e: string) => parseInt(e));

let ArrRoom: number[] = new Array(iN).fill(0);
let iIndex: number = 0;

for (let i = 1; i <= iG; ++i) {
  let iPeople: number = parseInt(input[i]);
  while (iIndex < iN) {
    if (iPeople === 0) {
      break;
    }
    if (iPeople === 1) {
      ArrRoom[iIndex++] = 1;
      iPeople -= 1;
    }
    else {
      ArrRoom[iIndex++] = 2;
      iPeople -= 2;
    }
  }
  for (let j = 0; j < iN; ++j) {
    if (iPeople === 0) {
      break;
    }
    if (ArrRoom[j] === 1) {
      ArrRoom[j] = 2;
      iPeople -= 1;
    }
  }
}

let strAns: string = "";
for (let i = 0; i < iN; ++i) {
  strAns += ArrRoom[i] + "\n";
}
console.log(strAns);
