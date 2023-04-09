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
		vector<int> vecA(3, 0);
		vector<int> vecB(3, 0);

		for (int i = 0; i < 3; ++i) cin >> vecA[i];
		for (int i = 0; i < 3; ++i) cin >> vecB[i];
		sort(vecA.begin(), vecA.end());
		sort(vecB.begin(), vecB.end());
		bool bPossible = true;
		for (int i = 0; i < 3; ++i)
		{
			if (vecA[i] != vecB[i]) bPossible = false;
		}
		if (vecA[0] * vecA[0] + vecA[1] * vecA[1] != vecA[2] * vecA[2])
		{
			bPossible = false;
		}
		cout << (bPossible ? "YES\n" : "NO\n");
	}
	return 0;
}
