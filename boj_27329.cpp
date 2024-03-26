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

	string strWord;
	cin >> strWord;

	bool bPossible = true;
	int iHalf = iN / 2;
	for (int i = 0;i < iHalf;++i)
	{
		if (strWord[i] != strWord[iHalf + i])
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "Yes" : "No") << "\n";
	return 0;
}
