#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int iY, iC, iP;
    cin >> iY >> iC >> iP;
    
    iC /= 2;
    
    int iAns = 2000000000;
    iAns = min(iAns, iY);
    iAns = min(iAns, iC);
    iAns = min(iAns, iP);
    
    cout << iAns << "\n";
	return 0;
}
