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

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iN, iS;
		cin >> iN >> iS;
		string strWord;
		cin >> strWord;

		for (int t = 0;t < iS;++t)
		{
			strWord = strWord.substr(iN, strWord.length() - iN) + strWord;
		}
		cout << strWord << "\n";
	}

	return 0;
}
