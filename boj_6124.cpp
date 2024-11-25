#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int iN, iM;
   cin >> iN >> iM;

   vector<vector<int>> matNum(iN+1, vector<int>(iM+1, 0));
   for(int i=1;i<=iN;++i)
   {
      for(int j=1;j<=iM;++j)
      {
         cin >> matNum[i][j];
      }
   }

   int iMax = -1;
   int iR = 0;
   int iC = 0;

   for(int i=1;i<=iN-2;++i)
   {
      for(int j=1;j<=iM-2;++j)
      {
         int iSum = 0;
         for(int p=0;p<3;++p)
         {
            for(int q=0;q<3;++q)
            {
               iSum += matNum[i+p][j+q];
            }
         }
         if(iSum > iMax)
         {
            iMax = iSum;
            iR = i;
            iC = j;
         }
      }
   }

   cout << iMax << "\n";
   cout << iR << " " << iC << "\n";
   return 0;
}
