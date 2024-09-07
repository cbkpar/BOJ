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

	int iT;
	cin >> iT;

	while (iT--)
	{
		string strNum;
		cin >> strNum;

		int iTemp = 0;
		for (char ch : strNum)
		{
			iTemp *= 10;
			iTemp = (iTemp + ch - '0') % 9;
		}

		cout << (iTemp == 0 ? "YES" : "NO") << "\n";
	}

	return 0;
}
