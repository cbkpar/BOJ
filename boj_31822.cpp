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

	string strMain;
	cin >> strMain;

	int iN;
	cin >> iN;

	int iAns = 0;
	while (iN--)
	{
		string strSub;
		cin >> strSub;

		bool bPossible = true;
		for (int i = 0; i < 5; ++i)
		{
			if (strMain[i] != strSub[i])
			{
				bPossible = false;
			}
		}
		if (bPossible)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
