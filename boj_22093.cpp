#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int iT;
	cin >> iT;
	while(iT--)
	{
	    int iN, iA, iB;
	    cin >> iN >> iA >> iB;
	    
	    int iMin = max(0, iA - iB);
	    int iMax = min(iA, iN - iB);
	    
	    cout << iMin << " " << iMax << "\n";
	}
	
	return 0;
}
