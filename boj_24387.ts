const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let arrCost: number[] = input[0].split(' ').map((e: string) => parseInt(e));
let arrWeight: number[] = input[1].split(' ').map((e: string) => parseInt(e));

arrCost.sort((a: number, b: number): number => {
  return a - b;
});

arrWeight.sort((a: number, b: number): number => {
  return a - b;
});

let matCost: number[][] = new Array(3).fill(0).map(() => new Array(10));
let matWeight: number[][] = new Array(3).fill(0).map(() => new Array(10));
let arrAns: number[] = new Array(20).fill(0);

for (let i = 0; i < 3; ++i) {
  for (let j = 0; j < 10; ++j) {
    matCost[i][j] = arrCost[i] % 10;
    arrCost[i] = Math.trunc(arrCost[i] / 10);
    matWeight[i][j] = arrWeight[i] % 10;
    arrWeight[i] = Math.trunc(arrWeight[i] / 10);
  }
}

for (let i = 0; i < 3; ++i) {
  for (let j = 0; j < 10; ++j) {
    for (let k = 0; k < 10; ++k) {
      arrAns[j + k] += matCost[i][j] * matWeight[i][k];
    }
  }
}

for (let i = 0; i < 19; ++i) {
  arrAns[i + 1] += Math.trunc(arrAns[i] / 10);
  arrAns[i] %= 10;
}

let strAns: string = "";
for (let i = 19; i >= 0; --i) {
  if (arrAns[i] != 0) {
    while (i >= 0) {
      strAns += arrAns[i--];
    }
    break;
  }
}
console.log(strAns);
