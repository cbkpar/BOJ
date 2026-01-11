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

	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		string strWord;
		cin >> strWord;
		int iLen = strWord.length();
		for (int j = 0; j < iLen; ++j)
		{
			if (strWord[j] >= 'a' && strWord[j] <= 'z')
			{
				cout << strWord[j];
			}
			else
			{
				if (j != 0) cout << "_";
				cout << (char)(strWord[j] - 'A' + 'a');
			}
		}
		cout << "\n";
	}
	return 0;
}
