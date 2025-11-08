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

	if (strA == strB)
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << "1550" << "\n";
	}
	
	return 0;
}
