const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

const dX: number[] = [-1, 0, 1, 0];
const dY: number[] = [0, -1, 0, 1];

class queue<T> {
  arr: T[];
  length: number;
  head: number;
  tail: number;

  constructor(length: number = 16) {
    this.arr = new Array(length).fill(undefined);
    this.length = length;
    this.head = 0;
    this.tail = 0;
  }

  push(e: T) {
    this.arr[this.tail] = e;
    this.tail = (this.tail + 1) % this.length;
    if (this.tail === this.head) {
      this.doubleCapacity();
    }
  }

  front(): T {
    if (this.head === this.tail) {
      throw new Error('queue is empty');
    }
    return this.arr[this.head];
  }

  pop() {
    if (this.head === this.tail) {
      throw new Error('queue is empty');
    }
    this.head = (this.head + 1) % this.length;
  }

  IsEmpty(): boolean {
    return this.head === this.tail;
  }

  doubleCapacity() {
    let p: number = this.head;
    let n: number = this.length;
    let newCapacity: number = n << 1;
    let arr: T[] = new Array(newCapacity).fill(undefined);
    let iIndex: number = 0;
    for (let i = p; i < n; ++i) {
      arr[iIndex++] = this.arr[i];
    }
    for (let i = 0; i < p; ++i) {
      arr[iIndex++] = this.arr[i];
    }
    this.arr = arr;
    this.head = 0;
    this.tail = n - 1;
    this.length = newCapacity;
  }
}

class Pos {
  X: number;
  Y: number;

  constructor(X: number, Y: number) {
    this.X = X;
    this.Y = Y;
  }
}

let [iN, iM]: number[] = input[0].split(' ').map((e: string) => parseInt(e));
let [iX1, iY1, iX2, iY2]: number[] = input[1].split(' ').map((e: string) => parseInt(e));
let matWorld: number[][] = new Array(iN).fill(0).map(() => new Array(iM).fill(0));
let matVisited: boolean[][] = new Array(iN).fill(false).map(() => new Array(iM).fill(false));

const qPos = new queue<Pos>();
qPos.push(new Pos(iX1 - 1, iY1 - 1));
matVisited[iX1 - 1][iY1 - 1] = true;


let iLine: number = 0;
for (let i = 0; i < iN; ++i) {
  for (let j = 0; j < iM; ++j) {
    if (input[i + 2][j] === '1') {
      matWorld[i][j] = 1;
    }
  }
}

let iAns: number = 1;
while (!qPos.IsEmpty()) {
  const qNextPos = new queue<Pos>();
  let bFound = false;
  while (!qPos.IsEmpty()) {
    let tPos: Pos = qPos.front();
    qPos.pop();
    if (tPos.X === iX2 - 1 && tPos.Y === iY2 - 1) {
      bFound = true;
      break;
    }
    for (let i = 0; i < 4; ++i) {
      let iNextX = tPos.X + dX[i];
      let iNextY = tPos.Y + dY[i];
      if (iNextX < 0 || iNextX > iN - 1 || iNextY < 0 || iNextY > iM - 1) continue;
      if (matVisited[iNextX][iNextY]) continue;
      matVisited[iNextX][iNextY] = true;
      if (matWorld[iNextX][iNextY] == 0) {
        qPos.push(new Pos(iNextX, iNextY));
      }
      else {
        qNextPos.push(new Pos(iNextX, iNextY));
      }
    }
  }

  if (bFound) {
    break;
  }
  if (!qNextPos.IsEmpty()) {
    while (!qNextPos.IsEmpty()) {
      let tPos: Pos = qNextPos.front();
      matWorld[tPos.X][tPos.Y] = 0;
      qPos.push(tPos);
      qNextPos.pop();
    }
    ++iAns;
  }
}

console.log(iAns);
