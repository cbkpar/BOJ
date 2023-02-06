#include <iostream>

using namespace std;

long long lCount[65][10] = { 0, };
long long lTotal[65] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; ++i)
	{
		lCount[1][i] = 1;
	}
	lTotal[1] = 10;
	for (int i = 2; i <= 64; ++i)
	{
		lTotal[i] = lCount[i][0] = 1;
		for (int j = 1; j < 10; ++j)
		{
			lCount[i][j] = lCount[i][j - 1] + lCount[i - 1][j];
			lTotal[i] += lCount[i][j];
		}
	}

	int iN;
	cin >> iN;

	while (iN--)
	{
		int iNumber;
		cin >> iNumber;
		cout << lTotal[iNumber] << "\n";
	}

	return 0;
}
