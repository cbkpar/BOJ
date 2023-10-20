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

	int iN, iM;
	cin >> iN >> iM;

	vector<string> vecWord(iN, "");
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecWord[i];
		iM -= vecWord[i].length();
	}

	int iCount = iM / (iN - 1);
	vector<int> vecCount(iN, 0);
	for (int i = 1; i < iN; ++i)
	{
		vecCount[i] = iCount;
		iM -= iCount;
	}

	for (int i = 1; i < iN; ++i)
	{
		if (iM > 0 && vecWord[i][0] >= 'a' && vecWord[i][0] <= 'z')
		{
			++vecCount[i];
			--iM;
		}
	}

	for (int i = iN - 1; i >= 1; --i)
	{
		if (iM > 0 && vecWord[i][0] >= 'A' && vecWord[i][0] <= 'Z')
		{
			++vecCount[i];
			--iM;
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		while (vecCount[i]-- > 0)
		{
			cout << "_";
		}
		cout << vecWord[i];
	}

	cout << "\n";
	return 0;
}
