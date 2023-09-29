const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iT: number = parseInt(input[0]);
for (let i = 1; i <= iT; ++i) {
  let arrDate: number[] = input[i].split(' ').map((e: string) => parseInt(e));
  let iAns: number = Math.trunc((arrDate[2] + arrDate[0] - 2) / arrDate[1]);

  if (arrDate[2] === 1) {
    ++iAns;
  }
  console.log(iAns);
}
