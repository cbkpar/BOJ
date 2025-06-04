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

	vector<bool> vecUsed(26, false);
	for(char ch : strA)
	{
		vecUsed[ch-'a'] = true;
	}

	for(char ch : strB)
	{
		if(!vecUsed[ch-'a'])
		{
			cout << ch;
		}
	}
	cout << "\n";
	return 0;
}
