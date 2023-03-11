#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ArrPrime[200001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 200000; i++) {
		for (int j = i * i; j <= 200000; j += i) {
			ArrPrime[j] = true;
		}
	}
	vector<int> vecPrime;
	for (int i = 2; i <= 200000; ++i)
	{
		if (!ArrPrime[i])
		{
			vecPrime.push_back(i);
		}
	}

	int iN;
	cin >> iN;
	cout << vecPrime[iN - 1] << "\n";

	return 0;
}
