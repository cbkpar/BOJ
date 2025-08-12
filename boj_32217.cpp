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
	
	int iSum = 0;
	for (int i = 0;i < iN;++i)
	{
		int iDegree;
		cin >> iDegree;
		iSum += iDegree;
	}

	int iAns = (180*(iN-1)) - iSum*2;
	cout << iAns << "\n";

	return 0;
}
