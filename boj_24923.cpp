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

	int iLen = strLine.length();

	if (strLine[iLen - 3] == 'e' && strLine[iLen - 2] == 'h' && strLine[iLen - 1] == '?')
	{
		cout << "Canadian!" << "\n";
	}
	else
	{
		cout << "Imposter!" << "\n";
	}

	return 0;
}
