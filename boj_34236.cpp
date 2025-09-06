#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int iN;
   cin >> iN;

   vector<int> vecNum(iN, 0);
   for (int i = 0; i < iN; ++i)
   {
      cin >> vecNum[i];
   }
   int iA = vecNum[0];
   int iD = vecNum[1] - vecNum[0];

   int iAns = iA + iN * iD;
   cout << iAns << "\n";

   return 0;
}
