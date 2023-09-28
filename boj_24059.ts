const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iN: number = parseInt(input[0]);
let arrNum: number[] = input[1].split(' ').map((e: string) => parseInt(e));
let iMod: number = parseInt(input[2]);

let CalcMod = (a: number, k: number, m: number): number => {
  let iRet: number = 0;
  while (k !== 0) {
    if (k % 2 === 1) {
      iRet = (iRet + a) % (m);
    }
    a = (a * 2) % (m);
    k = Math.trunc(k / 2);
  }
  return iRet;
}

let MathPow = (a: number, k: number, m: number): number => {
  let iRet: number = 1;
  while (k !== 0) {
    if (k % 2 === 1) {
      iRet = CalcMod(iRet, a, m);
    }
    a = CalcMod(a, a, m);
    k = Math.trunc(k / 2);
  }
  return iRet;
}

let iAns: number = arrNum[0];
if (arrNum[iN] % iMod === 0) {
  iAns = 0;
}
else {
  for (let i = 1; i <= iN; ++i) {
    iAns = MathPow(arrNum[i], iAns, iMod + i - iN);
  }
}

console.log(iAns % iMod);
