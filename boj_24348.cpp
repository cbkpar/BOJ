#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> vecNum(3);
	for (int i = 0; i < 3; ++i) cin >> vecNum[i];
	long long lAns = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				if (i == j || j == k || k == i) continue;
				lAns = max(lAns, vecNum[i] + vecNum[j] * vecNum[k]);
				lAns = max(lAns, vecNum[i] + vecNum[j] - vecNum[k]);
				lAns = max(lAns, vecNum[i] - vecNum[j] + vecNum[k]);
				lAns = max(lAns, vecNum[i] - vecNum[j] * vecNum[k]);
				lAns = max(lAns, vecNum[i] * vecNum[j] + vecNum[k]);
				lAns = max(lAns, vecNum[i] * vecNum[j] - vecNum[k]);
			}
		}
	}
	cout << lAns << "\n";
	return 0;
}
