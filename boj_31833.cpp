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

	int iN;
	cin >> iN;

	string strA = "";
	string strB = "";

	for (int i = 0;i < iN;++i)
	{
		string strNum;
		cin >> strNum;
		strA = strA + strNum;
	}

	for (int i = 0;i < iN;++i)
	{
		string strNum;
		cin >> strNum;
		strB = strB + strNum;
	}

	if (strA.length() == strB.length())
	{
		if (strA.compare(strB) <= 0)
		{
			cout << strA << "\n";
		}
		else
		{
			cout << strB << "\n";
		}
	}
	else if (strA.length() < strB.length())
	{
		cout << strA << "\n";
	}
	else
	{
		cout << strB << "\n";
	}

	return 0;
}
