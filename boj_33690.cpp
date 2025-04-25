#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;

	long long lTemp = 1;
	long long lAns = 1;
	for (int i = 0;i < 9;++i)
	{
		for (long long j = 1;j <= 9;++j)
		{
			long long lNum = lTemp * j;
			if (lNum <= lN)
			{
				++lAns;
			}
		}
		lTemp = lTemp * 10 + 1;
	}

	cout << lAns << "\n";
	return 0;
}
