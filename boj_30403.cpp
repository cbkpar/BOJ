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

	vector<bool> vecSmall(26, false);
	vector<bool> vecLarge(26, false);

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;

	for (char ch : strWord)
	{
		if (ch >= 'a' && ch <= 'z') vecSmall[ch - 'a'] = true;
		if (ch >= 'A' && ch <= 'Z') vecLarge[ch - 'A'] = true;
	}

	bool bSmall = false;
	bool bLarge = false;

	if (vecSmall['r' - 'a'] && vecSmall['o' - 'a'] && vecSmall['y' - 'a'] && vecSmall['g' - 'a'] && vecSmall['b' - 'a'] && vecSmall['i' - 'a'] && vecSmall['v' - 'a'])
	{
		bSmall = true;
	}
	if (vecLarge['r' - 'a'] && vecLarge['o' - 'a'] && vecLarge['y' - 'a'] && vecLarge['g' - 'a'] && vecLarge['b' - 'a'] && vecLarge['i' - 'a'] && vecLarge['v' - 'a'])
	{
		bLarge = true;
	}

	if (bSmall && bLarge)
	{
		cout << "YeS" << "\n";
	}
	else if (bSmall)
	{
		cout << "yes" << "\n";
	}
	else if (bLarge)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO!" << "\n";
	}

	return 0;
}
