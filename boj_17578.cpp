#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iM;
		cin >> iN >> iM;

		if (iN == 0 && iM == 0) break;

		map<char, pair<int, int>> mapKey;
		for (int i = 0; i < iN; ++i)
		{
			string strKey;
			cin >> strKey;
			for (int j = 0; j < iM; ++j)
			{
				if (strKey[j] == '_') continue;
				mapKey.insert({ strKey[j], { i,j } });
			}
		}
		string strCode;
		cin >> strCode;
		int iSum = 0;
		int iR = 0;
		int iC = 0;
		int iSize = strCode.length();
		for (int i = 0; i < iSize; ++i)
		{
			int iNextR = mapKey[strCode[i]].first;
			int iNextC = mapKey[strCode[i]].second;
			iSum += abs(iNextR - iR) + abs(iNextC - iC) + 1;
			iR = iNextR;
			iC = iNextC;
		}
		cout << iSum << "\n";
	}
	return 0;
}
