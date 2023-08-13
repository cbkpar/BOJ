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

	bool bWin = false;
	int iSize = strWord.length();

	int iLeft = 0;
	int iRight = iSize - 1;
	if (strWord[0] != strWord[iRight])
	{
		bWin = true;
	}
	else
	{
		bWin = false;
	}

	cout << (bWin ? "Win" : "Lose") << "\n";
	return 0;
}
