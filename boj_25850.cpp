#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<pair<int, int>> vecNum;
	for (int i = 0;i < iN;++i)
	{
		int iCount;
		cin >> iCount;

		for (int j = 0;j < iCount;++j)
		{
			int iValue;
			cin >> iValue;
			vecNum.push_back({ iValue, i });
		}
	}

	sort(vecNum.begin(), vecNum.end());
	int iSize = vecNum.size();
	for (int i = 0;i < iSize;++i)
	{
		cout << (char)('A' + vecNum[i].second);
	}
	cout << "\n";
	return 0;
}
