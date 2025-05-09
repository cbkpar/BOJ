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

	string strOrigin = "SciComLove";

	int iAns = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (strWord[i] != strOrigin[i])
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
