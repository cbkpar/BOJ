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

	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			if (i + j == 10)
			{
				++iAns;
			}
		}
	}
	if (iAns == 1)
	{
		printf("There is %d way to get the sum 10.\n", iAns);
	}
	else
	{
		printf("There are %d ways to get the sum 10.\n", iAns);
	}
	return 0;
}
