#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(5, 0);
	for (int i = 0;i < 5;++i) cin >> vecNum[i];
	sort(vecNum.begin(), vecNum.end());

	int iAns = 0;
	for (int i = 0;i < 5;++i)
	{
		for (int j = i + 1;j < 5;++j)
		{
			for (int k = j + 1;k < 5;++k)
			{
				if (vecNum[i] + vecNum[j] > vecNum[k]) ++iAns;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
