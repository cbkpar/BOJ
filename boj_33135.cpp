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

	string strLine;
	cin >> strLine;

	vector<int> vecCount(26, 0);
	for (char ch : strLine)
	{
		vecCount[ch - 'A']++;
	}

	int iAns = 0;
	for (int i = 0;i < 26;++i)
	{
		if (vecCount[i] > 1)
		{
			iAns += vecCount[i] - 1;
		}
	}
	
	cout << iAns << "\n";
	return 0;
}
