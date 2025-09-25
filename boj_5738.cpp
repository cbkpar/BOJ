#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iM;
		cin >> iN >> iM;
		if (iN == 0 && iM == 0) break;

		vector<int> vecA(iN, 0);
		vector<int> vecB(iM, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecA[i];
		}
		for (int i = 0;i < iM;++i)
		{
			cin >> vecB[i];
		}

		sort(vecA.begin(), vecA.end());
		sort(vecB.begin(), vecB.end());

		if (vecA[0] < vecB[1])
		{
			cout << "Y" << "\n";
		}
		else
		{
			cout << "N" << "\n";
		}
	}

	return 0;
}
