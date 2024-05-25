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

	string strKey;
	cin >> strKey;

	int iN;
	cin >> iN;

	int iNow = iN - 1;
	vector<int> vecDecode(26, 0);
	vector<bool> vecUse(26, false);
	for (char ch : strKey)
	{
		vecUse[ch - 'A'] = true;
		vecDecode[ch - 'A'] = (iNow++) % 26;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (!vecUse[i])
		{
			vecDecode[i] = (iNow++) % 26;
		}
	}

	string strCode;
	cin >> strCode;
	for (char ch : strCode)
	{
		cout << (char)(vecDecode[ch - 'A']+'A');
	}
	cout << "\n";
	return 0;
}
