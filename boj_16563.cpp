#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ArrPrime[2236] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 2235; i++) {
		for (int j = i * i; j <= 2235; j += i) {
			ArrPrime[j] = true;
		}
	}
	vector<int> vecPrime;
	for (int i = 2; i <= 2236; ++i)
	{
		if (!ArrPrime[i])
		{
			vecPrime.push_back(i);
		}
	}

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iNum;
		cin >> iNum;

		bool bFirst = true;

		for (int iPrime : vecPrime)
		{
			while (iNum % iPrime == 0)
			{
				cout << (bFirst ? "" : " ") << iPrime;
				bFirst = false;
				iNum /= iPrime;
			}
			if (iNum == 1) break;
		}
		if (iNum > 1) cout << (bFirst ? "" : " ") << iNum;
		cout << "\n";
	}
	return 0;
}
