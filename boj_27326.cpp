#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int iN;
   cin >> iN;

   vector<bool> vecVisited(iN + 1, false);

   for (int i = 1;i < 2 * iN;++i)
   {
      int iNum;
      cin >> iNum;
      vecVisited[iNum] = !vecVisited[iNum];
   }

   for (int i = 1;i <= iN;++i)
   {
      if (vecVisited[i])
      {
         cout << i << "\n";
      }
   }
   return 0;
}
