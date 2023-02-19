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

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strWord;
		cin >> strWord;

		vector<char> vecWord;
		int iSize = strWord.length();
		if (iSize == 1)
		{
			cout << strWord << "\n";
			continue;
		}
		vecWord.push_back(strWord[iSize - 1]);
		for (int i = iSize - 2; i >= 0; --i)
		{
			if (strWord[i] < strWord[i + 1])
			{
				for (int j = 0; j < i; ++j)
				{
					cout << strWord[j];
				}

				sort(vecWord.begin(), vecWord.end());
				int iWordSize = vecWord.size();
				for (int j = 0; j < iWordSize; ++j)
				{
					if (vecWord[j] > strWord[i])
					{
						cout << vecWord[j];
						vecWord[j] = strWord[i];
						sort(vecWord.begin(), vecWord.end());
						for (char ch : vecWord) cout << ch;
						cout << "\n";
						break;
					}
				}
				break;
			}
			else
			{
				vecWord.push_back(strWord[i]);
			}
			if (i == 0) cout << strWord << "\n";
		}
	}
	return 0;
}
