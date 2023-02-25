#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<long long> vecPreSum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecPreSum[i];
		vecPreSum[i] += vecPreSum[i - 1];
	}

	long long lMax = (long long)1000000001L * iN;
	int iAnsK = iN;

	for (int k = iN; k >= 1; --k)
	{
		for (int i = 1; i <= iN - k; ++i)
		{
			for (int j = i + k; j <= iN - k + 1; ++j)
			{
				long long lTemp = abs((vecPreSum[i + k - 1] - vecPreSum[i - 1]) - (vecPreSum[j + k - 1] - vecPreSum[j - 1]));
				if (lTemp < lMax)
				{
					lMax = lTemp;
					iAnsK = k;
				}

			}
		}
	}
	cout << iAnsK << "\n" << lMax << "\n";

	return 0;
}
