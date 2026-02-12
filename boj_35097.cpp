#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;

		int iAns = 0;
		for (int i = 1; i <= iN; ++i)
		{
			for (int j = 1; j <= iN; ++j)
			{
				iAns += i * j;
			}
		}
		cout << iAns << "\n";
	}

	return 0;
}
