#include <iostream>

using namespace std;

long long llPos[100000][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> llPos[i][j];
		}

	}
	int iM;
	cin >> iM;
	for (int i = 0; i < iM; ++i)
	{
		long long llX, llY, llZ, llR;
		cin >> llX >> llY >> llZ >> llR;
		int iSum = 0;
		for (int j = 0; j < iN; ++j)
		{
			long long llDistance = 0;
			llDistance += (llPos[j][0] - llX)*(llPos[j][0] - llX);
			llDistance += (llPos[j][1] - llY)*(llPos[j][1] - llY);
			llDistance += (llPos[j][2] - llZ)*(llPos[j][2] - llZ);
			if (llDistance <= llR * llR)
			{
				++iSum;
			}
		}
		printf("%d\n", iSum);
	}
	return 0;
}
