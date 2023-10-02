const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

let [iS1, iS2] = input[0].split(' ').map((e: string) => parseInt(e));
console.log((iS1 * 2 < iS2 ? "H" : "E"));
