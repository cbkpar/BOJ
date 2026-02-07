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

	vector<int> vecCount(51, 0);

	int iN;
	cin >> iN;
	for (int t = 0; t < iN; ++t)
	{
		for (int i = 0; i < 50; ++i)
		{
			int iNum;
			cin >> iNum;
			vecCount[iNum]++;
		}
	}

	vector<int> vecAns;
	for (int i = 1; i <= 50; ++i)
	{
		if (vecCount[i] > 2 * iN)
		{
			vecAns.push_back(i);
		}
	}
	int iSize = vecAns.size();
	if (iSize == 0)
	{
		cout << "-1" << "\n";
	}
	else
	{
		for (int i = 0; i < iSize; ++i)
		{
			cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
		}
	}


	return 0;
}
