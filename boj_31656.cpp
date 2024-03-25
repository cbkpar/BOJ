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

	char chBefore = '-';

	string strLine;
	getline(cin, strLine);

	for (char ch : strLine)
	{
		if (ch != chBefore)
		{
			cout << ch;
		}
		chBefore = ch;
	}

	cout << "\n";
	return 0;
}
