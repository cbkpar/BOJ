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

	vector<int> vecCount(26, 0);

	string strA, strB;
	cin >> strA >> strB;
	for (char ch : strA) ++vecCount[ch - 'a'];
	for (char ch : strB) ++vecCount[ch - 'a'];

	for (int i = 0; i < 26; ++i)
	{
		while (vecCount[i]--)
		{
			cout << (char)(i + 'a');
		}
	}
	cout << "\n";
	return 0;
}
