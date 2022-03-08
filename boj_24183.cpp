#include <iostream>

using namespace std;

int main()
{
  double C4, A3, A4;
  scanf("%lf %lf %lf", &C4, &A3, &A4);
  C4 *= 0.229 * 0.324 * 2;
  A3 *= 0.297 * 0.420 * 2;
  A4 *= 0.21 * 0.297;
  cout.precision(10);
  cout << (C4 + A3 + A4) << endl;
  return 0;
}
