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
		string strA, strB;
		cin >> strA >> strB;

		int iLen = strA.length();
		for (int i = 0; i < iLen; ++i)
		{
			if (strA[i] == 'x' || strA[i] == 'X')
			{
				if (strB[i] >= 'a' && strB[i] <= 'z')
				{
					cout << (char)(strB[i]-'a'+'A');
				}
				else
				{
					cout << strB[i];
				}
			}
		}
	}
	cout << "\n";
	return 0;
}
