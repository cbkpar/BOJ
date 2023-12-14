#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   long long lN, lM;
   cin >> lN >> lM;

   long long lAns = lN + lM + min(lN,lM)/10;
   cout << lAns << "\n";
   return 0;
}
