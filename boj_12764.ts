const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
input = input.split("\n");

class MinHeap<T> {
  heap: T[];
  constructor() {
    this.heap = [];
  }

  insert(value: T) {
    this.heap.push(value);
    this.heapifyUp();
  }

  pop(): void {
    const count = this.heap.length;
    if (count <= 0) return;
    if (count === 1) this.heap = [];
    else {
      this.heap[0] = this.heap.pop() as T;
      this.heapifyDown();
    }
  }

  peek(): T {
    const count = this.heap.length;
    if (count <= 0) {
      throw new Error('heap is empty');
    }
    return this.heap[0] as T;
  }

  IsEmpty(): boolean {
    if (this.heap.length === 0) {
      return true;
    }
    return false;
  }

  getLeftChildIndex = (parentIndex: number) => parentIndex * 2 + 1;
  getRightChildIndex = (parentIndex: number) => parentIndex * 2 + 2;
  getParentIndex = (childIndex: number) => Math.floor((childIndex - 1) / 2);

  heapifyUp = () => {
    let index = this.heap.length - 1;
    const lastInsertedNode = this.heap[index]

    while (index > 0) {
      const parentIndex = this.getParentIndex(index)

      if (this.heap[parentIndex] > lastInsertedNode) {
        this.heap[index] = this.heap[parentIndex];
        index = parentIndex;
      } else {
        break;
      }
    }
    this.heap[index] = lastInsertedNode;
  }

  heapifyDown = () => {
    let index = 0
    const count = this.heap.length
    const rootNode = this.heap[index]

    while (this.getLeftChildIndex(index) < count) {
      const leftChildIndex = this.getLeftChildIndex(index)
      const rightChildIndex = this.getRightChildIndex(index)

      const smallerChildIndex = rightChildIndex < count && this.heap[rightChildIndex] < this.heap[leftChildIndex] ? rightChildIndex : leftChildIndex

      if (this.heap[smallerChildIndex] <= rootNode) {
        this.heap[index] = this.heap[smallerChildIndex];
        index = smallerChildIndex;
      } else {
        break;
      }
    }
    this.heap[index] = rootNode;
  }

}

let iN: number = parseInt(input[0]);
let matNum: number[][] = new Array(iN).fill(0).map(() => new Array(2).fill(0));
let arrCount: number[] = new Array(iN).fill(0);
let arrRemove: number[] = new Array(1000001).fill(-1);

const heapNum = new MinHeap<number>();

for (let i = 0; i < iN; ++i) {
  matNum[i] = input[i + 1].split(' ').map((e: string) => parseInt(e));
}

matNum.sort((o1: number[], o2: number[]): number => {
  if (o1[0] === o2[0]) return o2[1] - o1[1];
  return o1[0] - o2[0];
});

let iTime: number = 0;

let iAns: number = 0;
for (let i = 0; i < iN; ++i) {
  let iS = matNum[i][0];
  let iE = matNum[i][1];
  while (iTime < iS) {
    if (arrRemove[iTime] !== -1) {
      heapNum.insert(arrRemove[iTime]);
    }
    ++iTime;
  }

  if (heapNum.IsEmpty()) {
    ++arrCount[iAns];
    arrRemove[iE] = iAns++;
  }
  else {
    let iNum: number = heapNum.peek();
    heapNum.pop();
    ++arrCount[iNum];
    arrRemove[iE] = iNum;
  }
}

let strAns: string = "";
for (let i = 0; i < iAns; ++i) {
  strAns += arrCount[i];
  if (i !== iAns - 1) {
    strAns += " ";
  }
}

console.log(iAns);
console.log(strAns);
