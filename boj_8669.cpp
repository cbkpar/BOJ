#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<bool> vecCount(1000001, false);
	for (int i = 0;i < iN;++i)
	{
		int iG, iR;
		cin >> iG >> iR;

		vecCount[iR] = true;
	}

	int iAns = 0;
	for (int i = 1;i <= 1000000;++i)
	{
		if (vecCount[i])
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
