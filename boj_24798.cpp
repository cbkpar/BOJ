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

	int iL, iW;
	cin >> iL >> iW;

	if (iW < iL || iL * 26 < iW)
	{
		cout << "impossible" << "\n";
		return 0;
	}
	else
	{
		iW -= iL;
		for (int i = 0;i < iL;++i)
		{
			if (iW >= 25)
			{
				cout << "z";
				iW -= 25;
			}
			else
			{
				cout << (char)('a' + iW);
				iW = 0;
			}
		}
		cout << "\n";
	}

	return 0;
}
