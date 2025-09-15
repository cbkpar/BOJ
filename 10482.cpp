#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> vecPrime(32001, false);
	for (int i = 2;i * i <= 32000;++i)
	{
		for (int j = i * i;j <= 32000;j += i)
		{
			vecPrime[j] = true;
		}
	}
	vecPrime[0] = vecPrime[1] = true;

	int iT;
	cin >> iT;
	for (int t = 0;t < iT;++t)
	{
		if (t != 0) cout << "\n";

		int iN;
		cin >> iN;
		vector<int> vecNum;
		for (int i = 2;i <= iN;++i)
		{
			if (i > iN - i) break;
			if (!vecPrime[i] && !vecPrime[iN - i])
			{
				vecNum.push_back(i);
			}
		}
		cout << iN << " has " << vecNum.size() << " representation(s)\n";
		for (int iNum : vecNum)
		{
			cout << iNum << "+" << (iN - iNum) << "\n";
		}
	}
	return 0;
}
