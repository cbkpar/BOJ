#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		vector<int> vecNum(iN, 0);
		for (int i = 0;i < iN;++i) cin >> vecNum[i];

		for (int i = 1;i < iN - 1;++i)
		{
			if (vecNum[i] != vecNum[i - 1] + 1 && vecNum[i] != vecNum[i + 1] - 1)
			{
				cout << (i+1) << "\n";
			}
		}
	}

	return 0;
}
