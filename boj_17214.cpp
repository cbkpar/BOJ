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

	string strExpress;
	cin >> strExpress;

	if (strExpress == "0")
	{
		cout << "W\n";
		return 0;
	}

	long long lA = 0;
	long long lB = 0;

	long long lTemp = 0;
	bool bMinus = false;

	for (char ch : strExpress)
	{
		if (ch == 'x')
		{
			lA = lTemp / 2;
			if (bMinus) lA *= -1;
			bMinus = false;
			lTemp = 0;
		}
		else if (ch == '+')
		{
			lTemp = 0;
		}
		else if (ch == '-')
		{
			bMinus = true;
		}
		else
		{
			lTemp *= 10;
			lTemp += ch - '0';
		}
	}
	lB = lTemp;
	if (bMinus) lB *= -1;

	if (lA != 0)
	{
		if (lA == -1)
		{
			cout << "-";
		}
		else if (lA != 1)
		{
			cout << lA;
		}
		cout << "xx";
	}
	if (lB != 0)
	{
		if (lB > 0 && lA != 0)
		{
			cout << "+";
		}
		if (lB == -1)
		{
			cout << "-";
		}
		else if (lB != 1)
		{
			cout << lB;
		}
		cout << "x";
	}
	cout << "+W\n";
	return 0;
}
