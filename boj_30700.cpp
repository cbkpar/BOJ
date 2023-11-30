#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string strWord;
	cin >> strWord;

	int iAns = 0;
	for (char ch : strWord)
	{
		if (iAns % 5 == 0 && ch == 'K') ++iAns;
		if (iAns % 5 == 1 && ch == 'O') ++iAns;
		if (iAns % 5 == 2 && ch == 'R') ++iAns;
		if (iAns % 5 == 3 && ch == 'E') ++iAns;
		if (iAns % 5 == 4 && ch == 'A') ++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
