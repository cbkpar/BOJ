#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strCode;
	cin >> strCode;

	int iPower = 0;
	int iRotate = 0;

	for (char ch : strCode)
	{
		if (ch == 'R')
		{
			++iRotate;
		}
		else
		{
			--iRotate;
		}
		if (iRotate == -4) iRotate = 0;
		if (iRotate == 4) iRotate = 0, ++iPower;
	}

	cout << iPower << "\n";

	return 0;
}
