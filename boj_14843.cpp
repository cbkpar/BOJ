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

	double dSum = 0;
	for (int i = 0;i < iN;++i)
	{
		double dS, dA, dT, dM;
		cin >> dS >> dA >> dT >> dM;
		dSum += dS * (1 + 1.0 / dA) * (1 + dM / dT) / 4.0;
	}

	int iP;
	cin >> iP;

	int iRank = 1;
	for (int i = 0;i < iP;++i)
	{
		double dScore;
		cin >> dScore;

		if (dScore > dSum)
		{
			++iRank;
		}
	}

	if (iRank * 100 / (iP + 1) <= 15)
	{
		printf("The total score of Younghoon \"The God\" is %.02f.\n", dSum);
	}
	else
	{
		printf("The total score of Younghoon is %.02f.\n", dSum);
	}

	return 0;
}
