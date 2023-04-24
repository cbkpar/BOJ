#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ArrPrime[119] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 118; i++) {
		for (int j = i * i; j <= 118; j += i) {
			ArrPrime[j] = true;
		}
	}
	vector<int> vecPrime;
	for (int i = 2; i <= 118; ++i)
	{
		if (!ArrPrime[i])
		{
			vecPrime.push_back(i);
		}
	}
	vector<bool> vecArtificial(119, false);
	for (int p1 : vecPrime)
	{
		for (int p2 : vecPrime)
		{
			int iSum = p1 + p2;
			if (iSum <= 118)
			{
				vecArtificial[iSum] = true;
			}
		}
	}

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iNum;
		cin >> iNum;
		if (vecArtificial[iNum])
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
	return 0;
}
