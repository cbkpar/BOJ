#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   int iN, iM;
   cin >> iN >> iM;

   vector<vector<long long>> matNum(iN+1,vector<long long>(iM+1,0));

   matNum[0][0] = 1;
   for(int i=1;i<=iN;++i)
   {
      for(int j=1;j<=iM;++j)
      {
         matNum[i][j] = (matNum[i-1][j-1]+matNum[i-1][j]+matNum[i][j-1])%1000000007;
      }
   }
   cout << matNum[iN][iM] << "\n";
}
