#include <iostream>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	int iOddCount = 0;
	int iEvenCount = 0;

	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		if (iNumber % 2 == 0)
		{
			++iEvenCount;
		}
		else
		{
			++iOddCount;
		}
	}
	if (iOddCount == iEvenCount || iOddCount == iEvenCount + 1)
	{
		cout << "1\n";
	}
	else
	{
		cout << "0\n";
	}
	return 0;
}
