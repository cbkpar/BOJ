#include <iostream>
#include <string>

using namespace std;

long long arrNumber[51][51] = { 0, };
long long arrSum[51][51] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	for (int i = 1; i <= iN; ++i)
	{
		string strNumber;
		cin >> strNumber;
		for (int j = 1; j <= iM; ++j)
		{
			arrNumber[i][j] = strNumber[j - 1] - '0';
		}
	}

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			arrSum[i][j] = arrSum[i][j - 1] + arrSum[i - 1][j] - arrSum[i - 1][j - 1] + arrNumber[i][j];
		}
	}

	long long lMax = 0;

	for (int i = 2; i <= iN; ++i)
	{
		for (int j = i + 1; j <= iN; ++j)
		{
			long long lTemp = 1;
			lTemp *= arrSum[i - 1][iM];
			lTemp *= arrSum[j - 1][iM] - arrSum[i - 1][iM];
			lTemp *= arrSum[iN][iM] - arrSum[j - 1][iM];
			if (lTemp > lMax)
			{
				lMax = lTemp;
			}
		}
	}

	for (int i = 2; i <= iM; ++i)
	{
		for (int j = i + 1; j <= iM; ++j)
		{
			long long lTemp = 1;
			lTemp *= arrSum[iN][i - 1];
			lTemp *= arrSum[iN][j - 1] - arrSum[iN][i - 1];
			lTemp *= arrSum[iN][iM] - arrSum[iN][j - 1];
			if (lTemp > lMax)
			{
				lMax = lTemp;
			}
		}
	}

	for (int i = 2; i <= iN; ++i)
	{
		for (int j = 2; j <= iM; ++j)
		{
			long long lAreaA = arrSum[i - 1][j - 1];
			long long lAreaB = arrSum[i - 1][iM] - lAreaA;
			long long lAreaC = arrSum[iN][j - 1] - lAreaA;
			long long lAreaD = arrSum[iN][iM] - lAreaB - lAreaC - lAreaA;

			if (lMax < (lAreaA + lAreaB) * lAreaC * lAreaD)
			{
				lMax = (lAreaA + lAreaB) * lAreaC * lAreaD;
			}
			if (lMax < (lAreaB + lAreaD) * lAreaC * lAreaA)
			{
				lMax = (lAreaB + lAreaD) * lAreaC * lAreaA;
			}
			if (lMax < (lAreaD + lAreaC) * lAreaA * lAreaB)
			{
				lMax = (lAreaD + lAreaC) * lAreaA * lAreaB;
			}
			if (lMax < (lAreaC + lAreaA) * lAreaB * lAreaD)
			{
				lMax = (lAreaC + lAreaA) * lAreaB * lAreaD;
			}
		}
	}

	cout << lMax << "\n";

	return 0;
}
