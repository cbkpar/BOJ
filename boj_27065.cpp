#include <iostream>

using namespace std;

int ArrSum[5001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 5000; ++i)
	{
		for (int j = i * 2; j <= 5000; j += i)
		{
			ArrSum[j] += i;
		}
	}

	int iT;
	cin >> iT;

	while (iT--)
	{
		int iN;
		cin >> iN;
		bool bCheck = true;
		if (ArrSum[iN] <= iN)
		{
			bCheck = false;
		}
		else
		{
			for (int i = 1; i < iN; ++i)
			{
				if (iN % i == 0)
				{
					if (ArrSum[i] > i)
					{
						bCheck = false;
					}
				}
			}
		}
		cout << (bCheck?"Good Bye\n":"BOJ 2022\n");
	}

	return 0;
}
