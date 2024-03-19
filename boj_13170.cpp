#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   int iN, iK, iP, iW;
   cin >> iN >> iK >> iP >> iW;

   int iAns = (iP+iW-1)/iW;
   cout << iAns << "\n";
}
