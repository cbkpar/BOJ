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
    
    for(int i=0;i<iN;++i)
    {
        int iLevel;
        cin >> iLevel;
        
        int iAns = -1;
        if(iLevel == 300) iAns = 1;
        if(iLevel < 300 && iLevel >= 275) iAns = 2;
        if(iLevel < 275 && iLevel >= 250) iAns = 3;
        if(iLevel < 250) iAns = 4;
        
        cout << iAns << (i==iN-1?"\n":" ");
    }

	return 0;
}
