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

	int iLen;
	cin >> iLen;

	string strJQbit, strJKey, strEQbit, strEKey;
	cin >> strJQbit >> strJKey >> strEQbit >> strEKey;

	for (int i = 0; i < iLen; ++i)
	{
		if (strJQbit[i] == strEQbit[i])
		{
			if (strJKey[i] != strEKey[i])
			{
				cout << "htg!" << "\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < iLen; ++i)
	{
		if (strJQbit[i] == strEQbit[i])
		{
			cout << strJKey[i];
		}
	}
	cout << "\n";

	return 0;
}
