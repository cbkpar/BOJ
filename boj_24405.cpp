#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int iLen = str.length();
	int iPos = -1;
	for (int i = 0; i < iLen; ++i)
	{
		if ('(' == str[i])
		{
			iPos = i;
		}
	}
	if (iPos == iLen - iPos - 2)
	{
		cout << "correct" << endl;
	}
	else
	{
		cout << "fix" << endl;
	}
	return 0;
}
