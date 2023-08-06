#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum;
	vecNum.push_back(4);
	vecNum.push_back(7);
	int iLast = -1;
	for (int i = 0; i < 8; ++i)
	{
		int iSize = vecNum.size();
		for (int j = iLast + 1; j < iSize; ++j)
		{
			vecNum.push_back(vecNum[j] * 10 + 4);
			vecNum.push_back(vecNum[j] * 10 + 7);
			iLast = j;
		}
	}

	int iAns = 0;

	int iA, iB;
	cin >> iA >> iB;
	for (int iNum : vecNum)
	{
		if (iNum >= iA && iNum <= iB)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
