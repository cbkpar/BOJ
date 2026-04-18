#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN, iC;
	cin >> iN >> iC;
	
	int iAns = 10000000;
	for (int i = 0;i < iN;++i)
	{
		int iP, iD, iV;
		cin >> iP >> iD >> iV;
		int iCost = iP + iD + iV * iC;
		iAns = min(iAns, iCost);
	}

	cout << iAns << "\n";
	return 0;
}
