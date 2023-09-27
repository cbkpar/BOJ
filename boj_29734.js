const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

const [iN, iM] = input[0].split(' ').map((e) => parseInt(e));
const [iT, iS] = input[1].split(' ').map((e) => parseInt(e));

let iZip = parseInt((iN - 1) / 8) * iS + iN;
let iDok = (parseInt((iM - 1) / 8) * 2 + 1) * iT + parseInt((iM - 1) / 8) * iS + iM;

if (iZip < iDok) {
  console.log("Zip");
  console.log(iZip);
}
else {
  console.log("Dok");
  console.log(iDok);
}
