#include <iostream>

using namespace std;

long long arrNumber[500] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		cin >> arrNumber[i];
	}

	int iMax = iN;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = i + 1; j < iN; ++j)
		{
			long long lStep = (arrNumber[j] - arrNumber[i]);
			int iCount = 0;
			for (int k = 0; k < iN; ++k)
			{
				if (arrNumber[k] * (j - i) != arrNumber[i] * (j - i) + (k - i) * lStep)
				{
					++iCount;
				}
			}
			if (iCount < iMax)
			{
				iMax = iCount;
			}
		}
	}
	cout << iMax << "\n";

	return 0;
}
