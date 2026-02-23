#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;

	int iAns = 0;
	for (int i = 0;i < iN - 4;++i)
	{
		int iCount = 0;
		if (strWord[i + 0] == 'e') ++iCount;
		if (strWord[i + 1] == 'a') ++iCount;
		if (strWord[i + 2] == 'g') ++iCount;
		if (strWord[i + 3] == 'l') ++iCount;
		if (strWord[i + 4] == 'e') ++iCount;
		iAns = max(iAns, iCount);
	}
	iAns = 5 - iAns;
	cout << iAns << "\n";

	return 0;
}
