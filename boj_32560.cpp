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

	vector<int> vecCountA(26, 0);
	vector<int> vecCountB(26, 0);
	for (char ch : strA)
	{
		vecCountA[ch - 'a']++;
	}
	for (char ch : strB)
	{
		vecCountB[ch - 'a']++;
	}

	for (int i = 0;i < 26;++i)
	{
		int iMin = max(vecCountA[i], vecCountB[i]);
		while (iMin-- > 0)
		{
			cout << (char)(i + 'a');
		}
	}
	cout << "\n";
	return 0;
}
