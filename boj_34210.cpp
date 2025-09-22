#include "aplusb.h"

std::vector<int> ACopy;
std::vector<int> BCopy;

void initialize(std::vector<int> A, std::vector<int> B) {
  ACopy = A;
  BCopy = B;
  return;
}

int answer_question(int i, int j) {
  return ACopy[i] + BCopy[j];
}
