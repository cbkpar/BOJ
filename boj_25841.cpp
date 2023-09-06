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
    
    int iAns = 0;
    
    int iS, iE, iD;
    cin >> iS >> iE >> iD;
    for(int i=iS;i<=iE;++i)
    {
        int iTemp = i;
        while(iTemp)
        {
            if(iTemp%10==iD) ++iAns;
            iTemp /= 10;
        }
    }
    
    cout << iAns << "\n";
	return 0;
}
