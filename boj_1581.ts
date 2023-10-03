const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let arrCount: number[] = input[0].split(' ').map((e: string) => parseInt(e));
let FF: number = arrCount[0];
let FS: number = arrCount[1];
let SF: number = arrCount[2];
let SS: number = arrCount[3];

let iAns = 0;
if (FF > 0 || FS > 0) {
  iAns += FF;
  if (FS > 0) {
    iAns += SS;
    if (FS > SF + 1) {
      FS = SF + 1;
    }
    if (SF > FS) {
      SF = FS;
    }
    iAns += SF + FS;
  }
}
else {
  iAns += SS;
  if (SF > 0) {
    iAns += 1;
  }
}

console.log(iAns);
