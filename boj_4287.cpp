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
		string strA, strB, strC;
		cin >> strA;
		if (strA == "#") break;
		cin >> strB >> strC;

		cout << strA << " ";
		cout << strB << " ";
		cout << strC << " ";
		int iLen = strA.length();
		for (int i = 0; i < iLen; ++i)
		{
			int iDiff = (strB[i] - strA[i] + 26) % 26;
			cout << (char)(((strC[i] - 'a') + iDiff) % 26 + 'a');
		}
		cout << "\n";
	}

	return 0;
}
