const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let [iN, iB, iA]: number[] = input[0].split(' ').map((e: string) => parseInt(e));
let arrNum: number[] = input[1].split(' ').map((e: string) => parseInt(e));

arrNum.sort((o1: number, o2: number): number => {
  return o1 - o2;
});

let iAns: number = 0;
for (let i = 0; i < iA; ++i) {
  if (iB >= arrNum[i] / 2) {
    iB -= arrNum[i] / 2;
    ++iAns;
  }
}
if (iAns === iA) {
  for (let i = iA; i < iN; ++i) {
    if (iB >= arrNum[i] / 2 + arrNum[i - iA] / 2) {
      iB -= arrNum[i] / 2 + arrNum[i - iA] / 2;
      ++iAns;
    }
  }
}
console.log(iAns);
