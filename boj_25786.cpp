#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int iA, iB;
    cin >> iA >> iB;
    
    int iDigit = 0;
    int iTemp = (iA>iB?iA:iB);
    while(iTemp)
    {
        ++iDigit;
        iTemp /= 10;
    }
    if(iDigit == 0) ++iDigit;
    
    vector<int> vecAns(iDigit, 9);
    for(int i = iDigit-1;i>=0;--i)
    {
        int iTempA = iA%10;
        int iTempB = iB%10;
        iA /= 10;
        iB /= 10;
        
        if(iTempA<=2&&iTempB<=2) vecAns[i] = 0;
        if(iTempA>=7&&iTempB>=7) vecAns[i] = 0;
    }
    for(int i=0;i<iDigit;++i)
    {
        cout << vecAns[i];
    }
    cout << "\n";
	return 0;
}
