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

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iN;
		cin >> iN;
		vector<int> vecNum(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecNum[i];
		}

		int iAns = 0;
		for (int i = 1;i < iN - 1;++i)
		{
			if (vecNum[i - 1] < vecNum[i] && vecNum[i] > vecNum[i + 1])
			{
				++iAns;
			}
		}

		cout << "Case #" << t << ": " << iAns << "\n";
	}
	return 0;
}
