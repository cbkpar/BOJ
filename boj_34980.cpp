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
    
    int iN;
    cin >> iN;
    
    string strA, strB;
    cin >> strA >> strB;
    
    int iCountA = 0;
    int iCountB = 0;
    bool bSame = true;
    
    for(int i=0;i<iN;++i)
    {
        if(strA[i] == 'w') ++iCountA;
        if(strB[i] == 'w') ++iCountB;
        if(strA[i] != strB[i]) bSame = false;
    }
    
    if(bSame)
    {
        cout << "Good" << "\n";
    }
    else
    {
        if(iCountA < iCountB) cout << "Manners maketh man" << "\n";
        if(iCountA == iCountB) cout << "Its fine" << "\n";
        if(iCountA > iCountB) cout << "Oryang" << "\n";
    }
    
	return 0;
}
