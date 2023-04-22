#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> vecExist(200001, false);

	int iN;
	cin >> iN;

	int iAns = 0;
	while (iN--)
	{
		int iA, iB;
		cin >> iA >> iB;

		if (iB == 0)
		{
			if (!vecExist[iA])
			{
				++iAns;
			}
			vecExist[iA] = false;
		}
		else
		{
			if (vecExist[iA])
			{
				++iAns;
			}
			vecExist[iA] = true;
		}
	}
	for (int i = 1; i <= 200000; ++i)
	{
		if (vecExist[i])
		{
			++iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}
