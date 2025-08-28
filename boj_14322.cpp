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

	int iT;
	cin >> iT;

	for (int t = 1;t <= iT;++t)
	{
		int iN;
		cin >> iN;
		cin.ignore();

		vector<string> vecName(iN, "");
		for (int i = 0;i < iN;++i)
		{
			getline(cin, vecName[i]);
		}
		sort(vecName.begin(), vecName.end());

		int iAns = 0;
		string strAns = "";
		
		for (int i = 0;i < iN;++i)
		{
			int iCount = 0;
			vector<bool> vecUsed(26, false);
			for (char ch : vecName[i])
			{
				if (ch < 'A' || ch > 'Z') continue;
				if (vecUsed[ch - 'A']) continue;
				vecUsed[ch - 'A'] = true;
				++iCount;
			}
			if (iCount > iAns)
			{
				iAns = iCount;
				strAns = vecName[i];
			}
		}

		cout << "Case #" << t << ": " << strAns << "\n";

	}
	return 0;
}
