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

	string strLine;
	getline(cin, strLine);

	for (char ch : strLine)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			int iNum = ch - 'a' + 1;
			cout << iNum / 10 << "" << iNum % 10;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			int iNum = ch - 'A' + 27;
			cout << iNum / 10 << "" << iNum % 10;
		}
		else if (ch >= '0' && ch <= '9')
		{
			cout << "#" << ch;
		}
		else
		{
			cout << ch;
		}
	}

	cout << "\n";
	return 0;
}
