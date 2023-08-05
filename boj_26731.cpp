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

	vector<bool> vecVisited(26, false);
	
	string strWord;
	cin >> strWord;

	for (char ch : strWord)
	{
		vecVisited[ch - 'A'] = true;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (!vecVisited[i])
		{
			cout << (char)(i + 'A') << "\n";
		}
	}
	return 0;
}
