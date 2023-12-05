#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   int iN;
   cin >> iN;

   vector<pair<int,int>> vecPos(iN);
   for(int i=0;i<iN;++i)
   {
      cin >> vecPos[i].second >> vecPos[i].first;
   }

   sort(vecPos.begin(), vecPos.end());

   cout << vecPos[0].second << " " << vecPos[0].first << "\n";
   return 0;
}
