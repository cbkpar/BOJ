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

    int iN, iM;
    cin >> iN >> iM;
    
    int iAns = 0;
    for(int i=0;i<iN;++i)
    {
        bool bAns = false;
        string strWord;
        cin >> strWord;
        for(int j=0;j<iM;++j)
        {
            if(strWord[j] == '+') bAns = true;
        }
        if(bAns) ++iAns;
    }
    
    cout << iAns << "\n";
	return 0;
}
