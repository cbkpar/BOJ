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

	vector<int> vecCount(26, 0);
	for (char ch : strWord)
	{
		vecCount[ch - 'A']++;
	}

	if (vecCount['U' - 'A'] == 0) cout << 'U';
	if (vecCount['A' - 'A'] == 0) cout << 'A';
	if (vecCount['P' - 'A'] == 0) cout << 'P';
	if (vecCount['C' - 'A'] == 0) cout << 'C';
	cout << "\n";

	return 0;
}
