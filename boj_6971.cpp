#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		int iN;
		cin >> iN;

		set<int> setNum;
		for (int i = 1; i <= iN; ++i)
		{
			if (iN % i == 0)
			{
				setNum.insert((iN / i) + i);
			}
			if (i * i >= iN)
			{
				break;
			}
		}

		bool bIsNasty = false;

		for (int i = 1; i <= iN; ++i)
		{
			if (iN % i == 0)
			{
				if (setNum.find((iN / i) - i) != setNum.end())
				{
					bIsNasty = true;
					break;
				}
			}
			if (i * i >= iN)
			{
				break;
			}
		}

		if (bIsNasty)
		{
			cout << iN << " is nasty" << "\n";
		}
		else
		{
			cout << iN << " is not nasty" << "\n";
		}
	}

	return 0;
}
