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

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	sort(vecNum.begin(), vecNum.end());

	int iAns = 2;
	for (int i = 1;i < iN;++i)
	{
		if (vecNum[i] <= i)
		{
			iAns = i + 1;
			break;
		}
	}

	cout << iAns << "\n";
	return 0;
}
