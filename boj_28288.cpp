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

	int iN;
	cin >> iN;
	
	vector<int> vecCount(5, 0);
	int iMax = 0;

	for (int i = 0;i < iN;++i)
	{
		string strDay;
		cin >> strDay;
		for (int j = 0;j < 5;++j)
		{
			if (strDay[j] == 'Y')
			{
				++vecCount[j];
				iMax = max(iMax, vecCount[j]);
			}
		}
	}

	vector<int> vecAns;
	for (int i = 0;i < 5;++i)
	{
		if (vecCount[i] == iMax)
		{
			vecAns.push_back(i + 1);
		}
	}
	
	int iSize = vecAns.size();
	for (int i = 0;i < iSize;++i)
	{
		if (i > 0) cout << ",";
		cout << vecAns[i];
	}
	cout << "\n";

	return 0;
}
