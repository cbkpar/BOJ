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

	string strWord;
	cin >> strWord;

	int iMax = 0;
	int iStrick = 0;
	for (char ch : strWord)
	{
		if (ch == '0')
		{
			++iStrick;
		}
		else
		{
			iStrick = 0;
		}
		iMax = max(iMax, iStrick);
	}

	int iAns = (iMax + 1) / 2;
	cout << iAns << "\n";
	return 0;
}
