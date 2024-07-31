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
		vector<int> vecA(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecA[i];
		}
		vector<int> vecB(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecB[i];
		}

		int iAns = 0;
		for (int i = 0;i < iN;++i)
		{
			if (vecA[i] != vecB[i])
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
