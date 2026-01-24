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

	int iT;
	cin >> iT;
	cin.ignore();
	while (iT-- > 0)
	{
		string strLine;
		getline(cin, strLine);

		int iNow = 0;
		for (char ch : strLine)
		{
			if (iNow % 3 == 0 && ((ch == 'p') || (ch == 'P'))) ++iNow;
			if (iNow % 3 == 1 && ((ch == 'l') || (ch == 'L'))) ++iNow;
			if (iNow % 3 == 2 && ((ch == 'u') || (ch == 'U'))) ++iNow;
		}
		cout << (iNow / 3) << "\n";
	}

	return 0;
}
