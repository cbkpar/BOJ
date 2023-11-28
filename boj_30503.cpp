#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   int iN;
   cin >> iN;

   vector<int> vecNum(iN, 0);
   for(int i=0;i<iN;++i)
   {
      cin >> vecNum[i];
   }

   int iQ;
   cin >> iQ;
   while(iQ--)
   {
      int iCommand;
      cin >> iCommand;
      if(iCommand == 1)
      {
         int iL, iR, iE;
         cin >> iL >> iR >> iE;

         int iCount = 0;
         for(int i=iL-1;i<iR;++i)
         {
            if(vecNum[i]==iE)
            {
               ++iCount;
            }
         }
         cout << iCount << "\n";
      }
      else
      {
         int iL, iR;
         cin >> iL >> iR;

         for(int i=iL-1;i<iR;++i)
         {
            vecNum[i] = 0;
         }
      }
   }
   return 0;
}
