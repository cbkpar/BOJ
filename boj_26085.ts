const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let [iN, iM]: number[] = input[0].split(' ').map((e: string) => parseInt(e));
let matWorld: number[][] = new Array(iN).fill(0).map(() => new Array(iM).fill(0));

let iCountZero: number = 0;
let iCountOne: number = 0;
let bPossible: boolean = false;

for (let i = 1; i <= iN; ++i) {
  matWorld[i - 1] = input[i].split(' ').map((e: string) => parseInt(e));
}

for (let i = 0; i < iN; ++i) {
  for (let j = 0; j < iM; ++j) {
    if (matWorld[i][j] === 0) {
      ++iCountZero;
    }
    else {
      ++iCountOne;
    }
    if (i < iN - 1) {
      if (matWorld[i][j] === matWorld[i + 1][j]) {
        bPossible = true;
      }
    }
    if (j < iM - 1) {
      if (matWorld[i][j] === matWorld[i][j + 1]) {
        bPossible = true;
      }
    }
  }
}

if (iCountOne % 2 === 1 || iCountZero % 2 === 1) {
  bPossible = false;
}

if (bPossible) {
  console.log(1);
}
else {
  console.log(-1);
}
