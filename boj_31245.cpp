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

	string strA, strB, strC;
	cin >> strA >> strB >> strC;

	cout << strA;
	if (strA[1] == strB[0])
	{
		cout << "'" << strB[1];
	}
	else
	{
		cout << strB;
	}
	if (strB[1] == strC[0])
	{
		cout << "'" << strC[1];
	}
	else
	{
		cout << strC;
	}
	cout << "\n";
	return 0;
}
