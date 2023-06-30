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

	for (int t = 0; t < iT; ++t)
	{
		int iN;
		cin >> iN;
		vector<int> vecNum(iN, 0);
		for (int i = 0; i < iN; ++i) cin >> vecNum[i];

		bool bIsGood = true;
		for (int i = 1; i < iN; ++i)
		{
			if (vecNum[i] < vecNum[i - 1] * 2)
			{
				bIsGood = false;
			}
		}
		if (t > 0) cout << "\n";
		cout << "Denominations:";
		for (int i = 0; i < iN; ++i) cout << " " << vecNum[i];
		cout << "\n";
		cout << (bIsGood ? "Good " : "Bad ") << "coin denominations!\n";
	}
	return 0;
}
