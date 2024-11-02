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

	string strTemp = "";
	bool bActive = false;

	for (char ch : strLine)
	{
		if (ch == '?')
		{
			if (bActive)
			{
				cout << "Forty-two is " << strTemp << ".\n";
			}
			else if (strTemp == "What is")
			{
				cout << "Forty-two is.\n";
      }
			strTemp = "";
			bActive = false;
		}
		else if (ch == '.')
		{
			strTemp = "";
			bActive = false;
		}
		else if (ch == ' ')
		{
			if (strTemp == "") continue;
			strTemp += ch;
			if (!bActive && strTemp == "What is ")
			{
				bActive = true;
				strTemp = "";
			}
		}
		else
		{
			strTemp += ch;
		}
	}

	return 0;
}
