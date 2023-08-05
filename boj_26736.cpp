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

	int iA = 0;
	int iB = 0;

	for (char ch : strWord)
	{
		if (ch == 'A') ++iA;
		if (ch == 'B') ++iB;
	}

	cout << iA << " : " << iB << "\n";
	return 0;
}
