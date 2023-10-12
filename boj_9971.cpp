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

	while (true)
	{
		string strStart;
		string strArticle;
		string strEnd;

		getline(cin, strStart);
		if (strStart == "ENDOFINPUT")
		{
			break;
		}
		getline(cin, strArticle);
		getline(cin, strEnd);

		for (char ch : strArticle)
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				cout << (char)((ch - 'A' + 21) % 26 + 'A');
			}
			else
			{
				cout << ch;
			}
		}
		cout << "\n";
	}
	return 0;
}
