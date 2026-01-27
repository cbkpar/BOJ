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
		vector<char> vecWord(26, 0);
		for (int i = 0;i < 26;++i)
		{
			vecWord[i] = (char)('a' + i);
		}

		int iN;
		cin >> iN;
		for (int i = 0;i < iN;++i)
		{
			int iIndex;
			cin >> iIndex;
			cout << vecWord[iIndex];
			char chTemp = vecWord[iIndex];
			for (int j = iIndex;j > 0;--j)
			{
				vecWord[j] = vecWord[j - 1];
			}
			vecWord[0] = chTemp;
		}
		cout << "\n";
	}
	return 0;
}
