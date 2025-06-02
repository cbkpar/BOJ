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

	string strA, strB;
	cin >> strA >> strB;

	int iLen = min(strA.length(), strB.length());
	for (int i = 0;i < iLen;++i)
	{
		if (i % 2 == 0)
		{
			cout << strA[i];
		}
		else
		{
			cout << strB[i];
		}
	}
	cout << "\n";
	return 0;
}
