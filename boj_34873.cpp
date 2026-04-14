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

	vector<int> vecCount(iN * 2 + 1, 0);
	for (int i = 0;i < iN * 2;++i)
	{
		int iNum;
		cin >> iNum;
		vecCount[iNum]++;
	}

	bool bPossible = true;
	for (int i = 1;i <= iN * 2;++i)
	{
		if (vecCount[i] >= 3)
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "Yes" : "No") << "\n";
	return 0;
}
