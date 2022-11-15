#include <iostream>

using namespace std;

int arrNum[100] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iL;
	cin >> iN >> iL;

	for (int i = 0; i < iL; ++i)
	{
		cin >> arrNum[i];
	}
	int iCount = 0;
	for (int i = 1; i < iN; ++i)
	{
		int iDiff = 0;
		for (int j = 0; j < iL; ++j)
		{
			int iNum;
			cin >> iNum;
			iDiff += abs(arrNum[j] - iNum);
		}
		if (iDiff > 2000)
		{
			++iCount;
		}
	}
	if ((iN - 1) <= iCount * 2)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
