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
	vector<int> vecCount(4, 0);
	for (int i = 0;i < iN * 3;++i)
	{
		int iNum;
		cin >> iNum;
		vecCount[iNum]++;
	}

	for (int i = 1;i <= 3;++i)
	{
		if (vecCount[i] == iN - 1) cout << i << "\n";
	}
	for (int i = 1;i <= 3;++i)
	{
		if (vecCount[i] == iN + 1) cout << i << "\n";
	}

	return 0;
}
