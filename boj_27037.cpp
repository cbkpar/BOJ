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

	vector<bool> vecVisited(10000, false);
	int iAns = 0;
	
	while (true)
	{
		vecVisited[iN] = true;
		++iAns;
		int iTemp = (iN % 1000) / 10;
		iTemp = iTemp * iTemp;

		iN = iTemp;
		if (vecVisited[iN]) break;
	}

	cout << iAns << "\n";
	return 0;
}
