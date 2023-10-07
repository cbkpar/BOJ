const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let arrX: number[] = [];
let arrY: number[] = [];

let iN: number = parseInt(input[0]);
for (let i = 1; i <= iN; ++i) {
  let [iX, iY]: number[] = input[i].split(' ').map((e: string) => parseInt(e));
  arrX.push(iX);
  arrY.push(iY);
}
arrX.sort((o1: number, o2: number): number => {
  return o1 - o2;
});

arrY.sort((o1: number, o2: number): number => {
  return o1 - o2;
});

let iLastX: number = 10000000000;
let iLastY: number = 10000000000;

let iAns: number = 0;
for (let i = 1; i < iN; ++i) {
  if (arrX[i] === arrX[i - 1] && iLastX != arrX[i]) {
    ++iAns;
    iLastX = arrX[i];
  }
}
for (let i = 1; i < iN; ++i) {
  if (arrY[i] === arrY[i - 1] && iLastY != arrY[i]) {
    ++iAns;
    iLastY = arrY[i];
  }
}

console.log(iAns);
