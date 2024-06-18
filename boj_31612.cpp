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

	int iN;
	cin >> iN;
	string strWord;
	cin >> strWord;

	int iAns = 0;
	for (char ch : strWord)
	{
		if (ch == 'j') iAns += 2;
		if (ch == 'o') iAns += 1;
		if (ch == 'i') iAns += 2;
	}

	cout << iAns << "\n";
	return 0;
}
