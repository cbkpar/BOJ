#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
   int iN;
   cin >> iN;

   set<string> setWord;

   for(int i=0;i<iN;++i)
   {
      string strWord;
      cin >> strWord;
      vector<int> vecNum(26,0);
      int iLen = strWord.length();
      for(int j=0;j<iLen;++j)
      {
         ++vecNum[strWord[j]-'a'];
      }
      string strTemp = "";
      for(int j=0;j<26;++j)
      {
         if(vecNum[j]==10)
         {
            strTemp = strTemp + 'X';
         }
         else
         {
            strTemp = strTemp + (char)('0'+vecNum[j]);
         }
      }
      setWord.insert(strTemp);
   }

   cout << setWord.size() << "\n";
   return 0;
}
