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

	string strWord;
	cin >> strWord;

	vector<int> vecCount(10, 0);
	for (char ch : strWord)
	{
		++vecCount[ch - '0'];
	}

	for (int i = 9; i >= 0; --i)
	{
		while (vecCount[i]-- > 0)
		{
			cout << i;
		}
	}
	cout << "\n";

	return 0;
}
