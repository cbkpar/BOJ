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

	int iN, iL;
	cin >> iN >> iL;
	
	vector<int> vecCount(1001, 0);
	for (int i = 0; i < iN; ++i)
	{
		string strColor;
		cin >> strColor;
		char chBefore = '0';
		int iCount = 0;

		for (int i = 0; i < iL; ++i)
		{
			if (chBefore == '0' && strColor[i] == '1')
			{
				++iCount;
			}
			chBefore = strColor[i];
		}
		++vecCount[iCount];
	}

	for (int i = 1000; i >= 0; --i)
	{
		if (vecCount[i] > 0)
		{
			cout << i << " " << vecCount[i] << "\n";
			return 0;
		}
	}
	return 0;
}
