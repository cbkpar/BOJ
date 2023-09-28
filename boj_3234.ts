const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let [iLukaX, iLukaY] = input[0].split(' ').map((e: string) => parseInt(e));
let iN: number = parseInt(input[1]);
let strCommand: string = input[2];
let iX: number = 0;
let iY: number = 0;

let strAns: string = "";
let bFound: boolean = false;

let IsHear = () => {
  if (Math.abs(iLukaX - iX) <= 1 && Math.abs(iLukaY - iY) <= 1) return true;
  return false;
}

if (IsHear()) {
  bFound = true;
  strAns += "0\n";
}

for (let i = 0; i < iN; ++i) {
  switch (strCommand[i]) {
    case 'I':
      ++iX;
      break;
    case 'S':
      ++iY;
      break;
    case 'Z':
      --iX;
      break;
    case 'J':
      --iY;
      break;

  }
  if (IsHear()) {
    bFound = true;
    strAns += (i + 1) + "\n";
  }
}

if (bFound) {
  console.log(strAns);
}
else {
  console.log("-1");
}
