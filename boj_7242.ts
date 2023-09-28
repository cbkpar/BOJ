const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iN: number = parseInt(input[0]);
let iStart: number = 0;
let iEnd: number = 1440;

let CalcTime = (hr: number, min: number): number => {
  return hr * 60 + min;
}

let SplitTime = (time: number): number[] => {
  return [Math.trunc(time / 60), time % 60];
}

for (let i = 1; i <= iN; ++i) {
  let ArrNum: number[] = input[i].split(' ').map((e: string) => parseInt(e));
  let iS: number = CalcTime(ArrNum[0], ArrNum[1]);
  let iE: number = CalcTime(ArrNum[2], ArrNum[3]);

  iStart = Math.max(iStart, iS);
  iEnd = Math.min(iEnd, iE);
}

if (iStart >= iEnd) {
  console.log("NE");
}
else {
  console.log("TAIP");
  const ArrStart: number[] = SplitTime(iStart);
  const ArrEnd: number[] = SplitTime(iEnd);
  console.log(ArrStart[0] + " " + ArrStart[1] + " " + ArrEnd[0] + " " + ArrEnd[1]);
}
