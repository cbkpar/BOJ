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

	bool bChange = false;

	int iT;
	cin >> iT;
	cin.ignore();
	while (iT--)
	{
		string strLine;
		getline(cin, strLine);
		if (strLine == "Never gonna give you up")
		{

		}
		else if (strLine == "Never gonna let you down")
		{

		}
		else if (strLine == "Never gonna run around and desert you")
		{

		}
		else if (strLine == "Never gonna make you cry")
		{

		}
		else if (strLine == "Never gonna say goodbye")
		{

		}
		else if (strLine == "Never gonna tell a lie and hurt you")
		{

		}
		else if (strLine == "Never gonna stop")
		{

		}
		else
		{
			bChange = true;
		}
	}

	if (bChange)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}

	return 0;
}
