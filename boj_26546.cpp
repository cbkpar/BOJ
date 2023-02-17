#include <iostream>
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
		string strCode;
		cin >> strCode;

		int iS, iE;
		cin >> iS >> iE;

		int iSize = strCode.length();
		for (int i = 0; i < iSize; ++i)
		{
			if (i >= iS && i < iE) continue;
			cout << strCode[i];
		}
		cout << "\n";
	}

	return 0;
}
