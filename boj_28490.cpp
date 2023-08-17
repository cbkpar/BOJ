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

    int iMax = 0;
    for(int i=0;i<iN;++i)
    {
        int iH, iW;
        cin >> iH >> iW;
        iMax = max(iMax, iH*iW);
    }
    
    cout << iMax << "\n";
	return 0;
}
