const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iN = Number(input[0]);
let iSum = 0;
let ArrNum = input[1].split(' ').map((e) => parseInt(e));

for (let i = 0; i < iN; ++i) {
  iSum += ArrNum[i];
}

if (iSum > 0) {
  console.log("Right");
}
else if (iSum < 0) {
  console.log("Left");
}
else {
  console.log("Stay");
}
