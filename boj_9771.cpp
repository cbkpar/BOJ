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

	int iAns = 0;

	string strTemp;
	while (cin >> strTemp)
	{
		if (strTemp.find(strWord) != string::npos)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
