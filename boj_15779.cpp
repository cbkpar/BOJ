#include <iostream>

using namespace std;

int arrNumber[5001] = { 0, };
int matDP[5001][2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i) cin >> arrNumber[i];
	matDP[0][0] = matDP[0][1] = 1;
	for (int i = 1; i < iN; ++i)
	{
		matDP[i][0] = matDP[i][1] = 1;
		if (arrNumber[i] > arrNumber[i - 1]) matDP[i][0] = matDP[i - 1][1] + 1;
		if (arrNumber[i] < arrNumber[i - 1]) matDP[i][1] = matDP[i - 1][0] + 1;
	}

	int iAns = 1;
	for (int i = 0; i < iN; ++i)
	{
		if (matDP[i][0] > iAns) iAns = matDP[i][0];
		if (matDP[i][1] > iAns) iAns = matDP[i][1];
	}

	cout << iAns << "\n";

	return 0;
}
