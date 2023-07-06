#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int iN, iM, iK;
    cin >> iN >> iM >> iK;
    
    int iAns = 1;
    int iMax = 1000000000;
    
    for(int t=1;t<=iK;++t)
    {
        int iF, iD;
        cin >> iF >> iD;
        
        int iSum = iF + (iM-iD);
        if(iSum < iMax)
        {
            iMax = iSum;
            iAns = t;
        }
    }
    
    cout << iAns << "\n";
	return 0;
}
