#include <iostream>

using namespace std;

long long arrPoint[1001][2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	for (int i = 1; i <= iN; ++i)
	{
		cin >> arrPoint[i][0] >> arrPoint[i][1];
	}

	int iTest;
	cin >> iTest;
	while (iTest--)
	{
		int iNum;
		long long lDist;
		cin >> iNum >> lDist;
		int iCount = 0;
		for (int i = 1; i <= iN; ++i)
		{
			if (i == iNum)
			{
				continue;
			}
			long long ldX = arrPoint[i][0] - arrPoint[iNum][0];
			long long ldY = arrPoint[i][1] - arrPoint[iNum][1];
			if (ldX * ldX + ldY * ldY <= lDist * lDist)
			{
				++iCount;
			}
		}
		cout << iCount << "\n";
	}

	return 0;
}
