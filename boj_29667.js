const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

const [iA1, iB1] = input[0].split(':').map((e) => parseInt(e));
const [iB2, iA2] = input[1].split(':').map((e) => parseInt(e));

if (iB2 <= iA1 && iA2 <= iB1) {
  console.log("YES");
}
else {
  console.log("NO");
}
