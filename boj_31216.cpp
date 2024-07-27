#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool bPrime[1000001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bPrime[0] = bPrime[1] = true;
	for (int i = 2;i * i <= 1000000;++i)
	{
		for (int j = i * i;j <= 1000000;j += i)
		{
			bPrime[j] = true;
		}
	}

	vector<int> vecPrime;
	vecPrime.push_back(-1);

	for (int i = 2;i <= 1000000;++i)
	{
		if (!bPrime[i])
		{
			vecPrime.push_back(i);
		}
	}

	vector<int> vecSuperPrime;
	vecSuperPrime.push_back(-1);

	int iOrder = 1;
	for (int i = 2;i <= 1000000;++i)
	{
		if (!bPrime[i] && !bPrime[iOrder++])
		{
			vecSuperPrime.push_back(i);
		}
	}

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iNum;
		cin >> iNum;
		cout << vecSuperPrime[iNum] << "\n";
	}
	return 0;
}
