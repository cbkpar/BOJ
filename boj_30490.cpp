#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;

	int iCount = 0;
	while(lN > 0)
	{
		lN = min((lN+1)/2, lN-1);
		++iCount;
	}
	
	cout << iCount << "\n";
	return 0;
}
