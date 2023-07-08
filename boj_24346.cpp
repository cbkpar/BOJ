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

	vector<int> vecCount(256, 0);
	string strWord;
	cin >> strWord;

	for (char ch : strWord)
	{
		++vecCount[ch];
	}

	int iAns = 0;
	for (int i = 0; i < 256; ++i)
	{
		if (vecCount[i] % 2 == 1)
		{
			++iAns;
		}
	}
	if (iAns == 0) iAns = 1;
	cout << iAns << "\n";
	return 0;
}
