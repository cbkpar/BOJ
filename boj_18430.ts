const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

const dR: number[] = [-1, 0, 1, 0, -1];
const dC: number[] = [0, 1, 0, -1, 0];

function dfs(iIndex: number, iSum: number): void {
  if (iIndex === iN * iM) {
    iAns = Math.max(iAns, iSum);
    return;
  }

  dfs(iIndex + 1, iSum);

  let iR: number = Math.trunc(iIndex / iM);
  let iC: number = iIndex % iM;
  if (matVisited[iR][iC]) return;

  for (let i = 0; i < 4; ++i) {
    let bPossible: boolean = true;
    for (let j = 0; j < 2; ++j) {
      const iNextR = iR + dR[i + j];
      const iNextC = iC + dC[i + j];
      if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1) {
        bPossible = false;
        break;
      }
      if (matVisited[iNextR][iNextC]) {
        bPossible = false;
        break;
      }
    }

    matVisited[iR][iC] = true;
    if (bPossible) {
      let iAdd: number = matNum[iR][iC] * 2;
      for (let j = 0; j < 2; ++j) {
        const iNextR = iR + dR[i + j];
        const iNextC = iC + dC[i + j];
        matVisited[iNextR][iNextC] = true;
        iAdd += matNum[iNextR][iNextC];
      }
      dfs(iIndex + 1, iSum + iAdd);
      for (let j = 0; j < 2; ++j) {
        const iNextR = iR + dR[i + j];
        const iNextC = iC + dC[i + j];
        matVisited[iNextR][iNextC] = false;
      }
    }
    matVisited[iR][iC] = false;
  }
}

let [iN, iM]: number[] = input[0].split(' ').map((e: string) => parseInt(e));
let matNum: number[][] = new Array(iN).fill(0).map(() => new Array(iM).fill(0));
let matVisited: boolean[][] = new Array(iN).fill(false).map(() => new Array(iM).fill(false));

for (let i = 0; i < iN; ++i) {
  matNum[i] = input[i + 1].split(' ').map((e: string) => parseInt(e));
}

let iAns: number = 0;
dfs(0, 0);
console.log(iAns);
