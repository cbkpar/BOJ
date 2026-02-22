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

	int iN;
	cin >> iN;

	vector<int> vecCount(iN + 2, 0);
	for (int i = 0;i < iN;++i)
	{
		int iA, iB;
		cin >> iA >> iB;
		vecCount[iA]++;
		vecCount[iB]++;
	}

	int iMax = 0;
	for (int i = 1;i <= iN + 1;++i)
	{
		iMax = max(iMax, vecCount[i]);
	}

	int iAns = iN - iMax;
	cout << iAns << "\n";

	return 0;
}
