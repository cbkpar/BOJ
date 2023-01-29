#include <iostream>

using namespace std;

int ArrAfter[1000001] = { 0, };
int ArrIndex[1000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iFirst = 0;
	int iSecond = 1;
	int iLast = iN - 1;

	for (int i = 0; i < iN; ++i)
	{
		int iChoice;
		cin >> iChoice;
		if (iChoice == 1)
		{
			ArrAfter[iN - i - 1] = iFirst;
			iFirst = iSecond;
			++iSecond;
		}
		else if (iChoice == 2)
		{
			ArrAfter[iN - i - 1] = iSecond;
			++iSecond;
		}
		else
		{
			ArrAfter[iN - i - 1] = iLast;
			--iLast;
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		ArrIndex[ArrAfter[i]] = i + 1;
	}
	for (int i = 0; i < iN; ++i)
	{
		cout << ArrIndex[i] << (i == iN - 1 ? "\n" : " ");
	}

	return 0;
}
