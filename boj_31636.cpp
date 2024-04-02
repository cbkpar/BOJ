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

	int iLen;
	cin >> iLen;

	string strWord;
	cin >> strWord;

	int iMax = 0;
	int iNow = 0;
	for (char ch : strWord)
	{
		if (ch == 'o')
		{
			++iNow;
		}
		else
		{
			iNow = 0;
		}
		iMax = max(iMax, iNow);
	}

	cout << (iMax >= 3 ? "Yes" : "No") << "\n";
	return 0;
}
