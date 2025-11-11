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
	while (iT-- > 0)
	{
		int iR, iC;
		cin >> iR >> iC;
		int iCount = 0;
		for (int i = 0;i < iR;++i)
		{
			string strTemp;
			cin >> strTemp;
			for (int j = 0;j < iC;++j)
			{
				if (strTemp[j] == '.') ++iCount;
			}
		}
		cout << (iCount % 2 == 0 ? "pizza" : "sewon") << "\n";
	}

	return 0;
}
