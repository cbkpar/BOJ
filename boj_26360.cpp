#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iX;
	cin >> iX;

	int iScore = 0;
	int iFirst, iSecond;
	cin >> iFirst >> iSecond;

	if (iFirst == 1)
	{
		iScore += iX;
	}

	if (iSecond == 1)
	{
		int iCount = 0;
		if (iFirst == 1)
		{
			iCount = 1;
		}
		else
		{
			iCount = iX;
		}

		for (int i = 0;i < iCount;++i)
		{
			int iNum;
			cin >> iNum;

			if (iNum == 1)
			{
				++iScore;
			}
		}
	}

	cout << iScore << "\n";
	return 0;
}
