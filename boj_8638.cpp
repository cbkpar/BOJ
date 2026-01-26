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

	vector<int> vecNum(iN, 0);
	int iMax = -1;
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
		iMax = max(iMax, vecNum[i]);
	}

	for (int i = 0;i < iN;++i)
	{
		if (vecNum[i] == iMax)
		{
			cout << (char)('A' + i);
		}

	}
	cout << "\n";
	return 0;
}
