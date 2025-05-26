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

   int iN, iM, iK;
   cin >> iN >> iM >> iK;

   int iAns = 0;
   for(int i=0;i<iN;++i)
   {
      string strWord;
      cin >> strWord;

      int iNow = 0;
      for(int j=0;j<iM;++j)
      {
         if(strWord[j] == '0')
         {
            if(++iNow >= iK)
            {
               ++iAns;
            }
         }
         else
         {
            iNow = 0;
         }
      }
   }

   cout << iAns << "\n";
   return 0;
}
