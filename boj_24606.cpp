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

	int iCount = 0;
	for (int i = 0;i < 4;++i)
	{
		if (strA[i] != strB[i])
		{
			++iCount;
		}
	}

	cout << (1 << iCount) << "\n";
	return 0;
}
