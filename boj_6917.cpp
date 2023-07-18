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

    while(true)
    {
        string strWord;
        cin >> strWord;
        if(strWord == "quit!") break;
        
        int iLen = strWord.length();
        bool bChange = false;
        if(iLen >= 4)
        {
            if(strWord[iLen-2] == 'o' && strWord[iLen-1] == 'r')
            {
                switch(strWord[iLen-3])
                {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'y':
                    break;
                    default:
                    bChange = true;
                    break;
                }
            }
        }
        if(bChange)
        {
            for(int i=0;i<iLen-2;++i)
            {
                cout << strWord[i];
            }
            cout << "our\n";
        }
        else
        {
            cout << strWord << "\n";
        }
    }
	return 0;
}
