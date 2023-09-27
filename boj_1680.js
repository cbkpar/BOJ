const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let iT = Number(input[0]);
let iIndex = 1;
while (iT-- > 0) {
  let [iMaxW, iN] = input[iIndex++].split(' ').map((e) => parseInt(e));
  let iNowW = 0;
  let iNowPos = 0;
  let iAns = 0;
  while (iN-- > 0) {
    const [iX, iW] = input[iIndex++].split(' ').map((e) => parseInt(e));
    if (iNowW + iW === iMaxW) {
      iAns += iX;
      iNowPos = 0;
      iNowW = 0;
    }
    else if (iNowW + iW > iMaxW) {
      iAns += iX;
      if (iMaxW === iW) {
        iAns += iX;
        iNowPos = 0;
        iNowW = 0;
      }
      else {
        iNowW = iW;
        iNowPos = iX;
      }
    }
    else {
      iNowW += iW;
      iNowPos = iX;
    }
  }
  iAns += iNowPos;
  console.log(iAns * 2);
}
