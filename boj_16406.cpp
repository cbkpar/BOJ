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

	string strA, strB;
	cin >> strA >> strB;

	int iCount = 0;
	int iSize = strA.length();
	for (int i = 0; i < iSize; ++i)
	{
		if (strA[i] == strB[i])
		{
			++iCount;
		}
	}
	if (iCount > iN)
	{
		cout << (iSize - iCount + iN) << "\n";
	}
	else
	{
		cout << (iSize - iN + iCount) << "\n";
	}

	return 0;
}
