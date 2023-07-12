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
    vector<int> vecOrder(iN-1,0);
    for(int i=0;i<iN-1;++i) cin >> vecOrder[i];

    vector<int> vecAns(iN, 0);
    vecAns[0] = 1;
    for(int i=2;i<=iN;++i)
    {
        int iOrder = vecOrder[i-2];
        vecAns[iOrder+1] = i;
    }
    
    for(int i=0;i<iN;++i)
    {
        cout << vecAns[i] << (i==iN-1?"\n":" ");
    }
	return 0;
}
