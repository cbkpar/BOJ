#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 0;t < iT;++t)
	{
		vector<int> vecNum(6, 0);
		for (int i = 0;i < 6;++i)
		{
			cin >> vecNum[i];
			cout << vecNum[i] << (i == 5 ? "\n" : " ");
		}

		int iCountA = vecNum[0] + vecNum[1] + vecNum[2];
		int iCountB = vecNum[3] + vecNum[4] + vecNum[5];

		bool bCount = (iCountA > iCountB ? true : false);
		bool bGold = false;
		for (int i = 0;i < 3;++i)
		{
			if (vecNum[i] > vecNum[i + 3])
			{
				bGold = true;
				break;
			}
			else if (vecNum[i] == vecNum[i + 3])
			{
				continue;
			}
			else
			{
				break;
			}
		}

		if (bCount && bGold) cout << "both" << "\n";
		if (bCount && !bGold) cout << "count" << "\n";
		if (!bCount && bGold) cout << "color" << "\n";
		if (!bCount && !bGold) cout << "none" << "\n";

		cout << (t == iT - 1 ? "" : "\n");
	}


	return 0;
}
