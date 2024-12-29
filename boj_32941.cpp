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

	int iT, iX;
	cin >> iT >> iX;

	int iN;
	cin >> iN;

	bool bPossible = true;
	for (int i = 0;i < iN;++i)
	{
		int iM;
		cin >> iM;
		bool bFound = false;
		for (int j = 0;j < iM;++j)
		{
			int iNum;
			cin >> iNum;
			if (iNum == iX)
			{
				bFound = true;
			}
		}
		if (!bFound)
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "YES" : "NO") << "\n";
	return 0;
}
