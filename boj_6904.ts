const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iLine: number = 0;
let strAns: string = "";

const CalcPerimeter = (area: number): number[] => {
  let iSqrt: number = Math.floor(Math.sqrt(area));
  for (let i = iSqrt; i >= 1; --i) {
    if (area % i === 0) {
      return [i, area / i];
    }
  }
  return [1, area];
}

while (true) {
  let iNum: number = parseInt(input[iLine++]);
  if (iNum === 0) {
    break;
  }
  const arrLen: number[] = CalcPerimeter(iNum);
  const iPerimeter = (arrLen[0] + arrLen[1]) * 2;
  strAns += "Minimum perimeter is " + iPerimeter + " with dimensions " + arrLen[0] + " x " + arrLen[1] + "\n";
}

console.log(strAns);
