#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH;
	cin >> iH;
	string Command = "";
	cin >> Command;
	int iIndex = 0;
	int iSize = Command.length ();
	for (int i = 0; i < iSize; ++i)
	{
		if (Command[i] == 'L')
		{
			iIndex = iIndex * 2 + 1;
		}
		else if (Command[i] == 'R')
		{
			iIndex = iIndex * 2 + 2;
		}
	}
	cout << ((2 << iH) - iIndex - 1) << "\n";
	return 0;
}
