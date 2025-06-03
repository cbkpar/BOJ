#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool vecPrime[5000001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 5000000; i++) {
		for (int j = i * i; j <= 5000000; j += i) {
			vecPrime[j] = true;
		}
	}
	vecPrime[0] = vecPrime[1] = true;

	int iN;
	cin >> iN;

	int iS = 0;
	int iB = 0;

	for (int i = 1; i <= iN; ++i)
	{
		if (!vecPrime[i])
		{
			if (iB > 0)
			{
				--iB;
				++iS;
			}
			++iS;
		}
		else
		{
			++iB;
		}
	}

	cout << iB << " " << iS << "\n";
	return 0;
}
