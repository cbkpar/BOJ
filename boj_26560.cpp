#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
   int iN;
   cin >> iN;
   cin.ignore();

   while(iN--)
   {
      string strLine;
      getline(cin, strLine);

      int iLen = strLine.length();
      cout << strLine;
      if(strLine[iLen-1]!='.')
      {
         cout << ".";
      }
      cout << "\n";

   }
   return 0;
}
