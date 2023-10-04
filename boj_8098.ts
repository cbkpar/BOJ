const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iN: number = parseInt(input[0]);
let matNum: number[][] = new Array(iN).fill(0).map(() => new Array(2).fill(0));
let dp: number[] = new Array(30001).fill(0);

for (let i = 0; i < iN; ++i) {
  matNum[i] = input[i + 1].split(' ').map((e: string) => parseInt(e));
}

matNum.sort((o1: number[], o2: number[]): number => {
  if (o1[0] === o2[0]) return o2[1] - o1[1];
  return o1[0] - o2[0];
});

for (let i = 0; i < iN; ++i) {
  let iS = matNum[i][0];
  let iE = matNum[i][1];
  dp[iE] = Math.max(dp[iE], dp[iS] + iE - iS);
  for (let j = iE; j < 30001; ++j) {
    dp[j] = Math.max(dp[j], dp[j - 1]);
  }
}

let iAns: number = dp[30000];
console.log(iAns);
