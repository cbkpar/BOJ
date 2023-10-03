const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iT: number = parseInt(input[0]);

for (let t = 1; t <= iT; ++t) {
  let iLen: number = input[t].length;
  let strNum: string = input[t][0];
  let iCount: number = 1;
  let strAns: string = "";

  for (let i = 1; i < iLen; ++i) {
    if (input[t][i] !== input[t][i - 1]) {
      strAns += iCount.toString() + "" + strNum;
      strNum = input[t][i];
      iCount = 1;
    }
    else {
      ++iCount;
    }
  }
  if (iCount > 0) {
    strAns += iCount.toString() + "" + strNum;
  }
  console.log(strAns);
}
