#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	while (true)
	{
		string strLine;
		getline(cin, strLine);
		if (strLine == "I quacked the code!") break;

		int iLen = strLine.length();
		if (strLine[iLen - 1] == '.')
		{
			cout << "*Nod*" << endl;
		}
		else
		{
			cout << "Quack!" << endl;
		}
	}

	return 0;
}
