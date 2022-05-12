#include <iostream>

#define Min(a,b) (a<b)?a:b
#define INF 4200000000L

using namespace std;

long long arrBus[50][3];

int main()
{
	int iN;
	long long llT;
	cin >> iN >> llT;
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrBus[i][0] >> arrBus[i][1] >> arrBus[i][2];
	}

	long long llAnswer = INF;
	for (int i = 0; i < iN; ++i)
	{
		if (llT > arrBus[i][0] + arrBus[i][1] * (arrBus[i][2] - 1))
		{
			continue;
		}
		if (llT < arrBus[i][0])
		{
			llAnswer = Min(llAnswer, arrBus[i][0] - llT);
		}
		else
		{
			llAnswer = Min(llAnswer, (arrBus[i][0] + arrBus[i][1] * arrBus[i][2] - llT) % arrBus[i][1]);
		}
	}
	cout << (INF == llAnswer ? -1 : llAnswer) << endl;
	return 0;
}
