const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let [iN, iM]: number[] = input[0].split(' ').map((e: string) => parseInt(e));
let matWorld: number[][] = new Array(iN).fill(0).map(() => new Array(iM).fill(0));


let matZero: number[][] = [];
let matOne: number[][] = [];
let bPossible: boolean = false;

for (let i = 1; i <= iN; ++i) {
  matWorld[i - 1] = input[i].split(' ').map((e: string) => parseInt(e));
}

let iIndex: number = 2;
let strAns: string = "";

for (let i = 0; i < iN; ++i) {
  for (let j = 0; j < iM; ++j) {
    if (i < iN - 1) {
      if (matWorld[i][j] === matWorld[i + 1][j]) {
        bPossible = true;
        matWorld[i][j] = iIndex++;
        matWorld[i + 1][j] = iIndex++;
        strAns += (i + 1) + " " + (j + 1) + " " + (i + 2) + " " + (j + 1) + "\n";
      }
    }
    if (j < iM - 1) {
      if (matWorld[i][j] === matWorld[i][j + 1]) {
        bPossible = true;
        matWorld[i][j] = iIndex++;
        matWorld[i][j + 1] = iIndex++;
        strAns += (i + 1) + " " + (j + 1) + " " + (i + 1) + " " + (j + 2) + "\n";
      }
    }
  }
}

for (let i = 0; i < iN; ++i) {
  for (let j = 0; j < iM; ++j) {
    if (matWorld[i][j] === 0) {
      matZero.push([i + 1, j + 1]);
    }
    else if (matWorld[i][j] === 1) {
      matOne.push([i + 1, j + 1]);
    }
  }
}

if (matZero.length % 2 === 1 || matOne.length % 2 === 1) {
  bPossible = false;
}

if (bPossible) {
  console.log(1);
  for (let i = 0; i < matOne.length; i += 2) {
    strAns += matOne[i][0] + " " + matOne[i][1] + " " + matOne[i + 1][0] + " " + matOne[i + 1][1] + "\n";
  }
  for (let i = 0; i < matZero.length; i += 2) {
    strAns += matZero[i][0] + " " + matZero[i][1] + " " + matZero[i + 1][0] + " " + matZero[i + 1][1] + "\n";
  }
  console.log(strAns);
}
else {
  console.log(-1);
}
