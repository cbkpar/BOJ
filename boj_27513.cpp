#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	int iSum = iN * iM;
	if (iSum % 2 == 1) --iSum;
	cout << iSum << "\n";

	if (iN % 2 == 0)
	{
		for (int i = 1; i <= iN; ++i)
		{
			cout << i << " " << 1 << "\n";
		}
		for (int i = iN; i >= 1; --i)
		{
			if (i % 2 == 0)
			{
				for (int j = 2; j <= iM; ++j)
				{
					cout << i << " " << j << "\n";
				}
			}
			else
			{
				for (int j = iM; j >= 2; --j)
				{
					cout << i << " " << j << "\n";
				}
			}
		}
	}
	else
	{
		for (int i = 1; i <= iN; ++i)
		{
			cout << i << " " << 1 << "\n";
		}
		cout << iN << " 2\n";
		cout << (iN - 1) << " 2\n";
		for (int i = 3; i <= iM; ++i)
		{
			if (i % 2 == 1)
			{
				cout << (iN - 1) << " " << i << "\n";
			}
			else
			{
				cout << iN << " " << (i - 1) << "\n";
				cout << iN << " " << i << "\n";
				cout << (iN - 1) << " " << i << "\n";
			}
		}
		for (int i = iN - 2; i >= 1; --i)
		{
			if (i % 2 == 0)
			{
				for (int j = 2; j <= iM; ++j)
				{
					cout << i << " " << j << "\n";
				}
			}
			else
			{
				for (int j = iM; j >= 2; --j)
				{
					cout << i << " " << j << "\n";
				}
			}
		}
	}

	return 0;
}
