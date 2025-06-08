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

	while (true)
	{
		string strWord;
		cin >> strWord;
		if (strWord == "#") break;

		int iLen = strWord.length();
		bool bPossble = true;

		for (int i = 1; i < iLen; ++i)
		{
			int iDiff = 0;
			if (strWord[i - 1] < strWord[i])
			{
				iDiff = strWord[i] - strWord[i - 1];
				
			}
			else
			{
				iDiff = strWord[i] - strWord[i - 1] + 7;
			}
			if (iDiff % 2 == 1)
			{
				bPossble = false;
			}
		}

		if (bPossble)
		{
			cout << "That music is beautiful." << "\n";
		}
		else
		{
			cout << "Ouch! That hurts my ears." << "\n";
		}
	}
	return 0;
}
