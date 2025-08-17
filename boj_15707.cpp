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

	string strA, strB;
	cin >> strA >> strB;

	if (strA == "0" || strB == "0")
	{
		cout << "0" << "\n";
		return 0;
	}

	if(strA.length() >= 20 || strB.length() >= 20)
	{ 
		cout << "overflow" << "\n";
		return 0;
	}
	if (strA.length() == 19 && strA.compare("9223372036854775807") > 0)
	{
		cout << "overflow" << "\n";
		return 0;
	}
	if (strB.length() == 19 && strB.compare("9223372036854775807") > 0)
	{
		cout << "overflow" << "\n";
		return 0;
	}

	unsigned long long lA = stoull(strA);
	unsigned long long lB = stoull(strB);

	unsigned long long lR;
	cin >> lR;

	if (lA > lR / lB)
	{
		cout << "overflow" << "\n";
	}
	else
	{
		cout << lA * lB << "\n";
	}

	return 0;
}
