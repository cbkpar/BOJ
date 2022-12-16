#include <iostream>

using namespace std;

int ArrNumber[100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 1; i <= iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		ArrNumber[iNumber] = i;
	}
	int iCount = 0;
	for (int i = 2; i <= iN; ++i)
	{
		if (ArrNumber[i - 1] > ArrNumber[i])
		{
			++iCount;
		}
	}
	cout << iCount << "\n";
	return 0;
}
