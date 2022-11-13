#include <iostream>

using namespace std;

int arrScore[100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 1; i <= iN; ++i)
	{
		int iRank;
		cin >> iRank;
		arrScore[iRank] = iRank - i;
	}

	for (int i = 1; i <= iN; ++i)
	{
		cout << arrScore[i] << "\n";
	}
	return 0;
}
