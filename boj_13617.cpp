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

	int iN, iM;
	cin >> iN >> iM;

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		bool bPossible = true;
		for (int j = 0;j < iM;++j)
		{
			int iNum;
			cin >> iNum;
			if (iNum == 0) bPossible = false;
		}
		if (bPossible) ++iAns;
	}
	
	cout << iAns << "\n";
	return 0;
}
