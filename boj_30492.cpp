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

	vector<vector<int>> matCount(iM, vector<int>(26, 0));
	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;
		for (int j = 0;j < iM;++j)
		{
			matCount[j][strWord[j] - 'a']++;
		}
	}

	for (int i = 0;i < iM;++i)
	{
		int iAns = 0;
		int iMax = 0;
		for (int j = 0;j < 26;++j)
		{
			if (matCount[i][j] > iMax)
			{
				iMax = matCount[i][j];
				iAns = j;
			}
		}
		cout << (char)(iAns + 'a');
	}
	
	cout << "\n";
	return 0;
}
