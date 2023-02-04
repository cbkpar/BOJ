#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iOdd = 0;
	int iEven = 0;
	int iIndex = -1;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			int iNum;
			cin >> iNum;
			if (iNum == 1)
			{
				if ((i + j) % 2 == 0)
				{
					++iEven;
				}
				else
				{
					++iOdd;
				}
			}
			else if (iNum == 2)
			{
				iIndex = (i + j) % 2;
			}
		}
	}
	if (iIndex == 0)
	{
		if (iEven == 0)
		{
			cout << "Lena\n";
		}
		else
		{
			cout << "Kiriya\n";
		}
	}
	else
	{
		if (iOdd == 0)
		{
			cout << "Lena\n";
		}
		else
		{
			cout << "Kiriya\n";
		}
	}


	return 0;
}
