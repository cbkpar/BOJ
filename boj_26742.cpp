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

	int iB = 0;
	int iC = 0;

	for (char ch : strWord)
	{
		if (ch == 'B') ++iB;
		if (ch == 'C') ++iC;
	}

	cout << ((iB / 2) + (iC / 2)) << "\n";
	return 0;
}
