#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iCount = 0;

	for (int i = 0;i < 3;++i)
	{
		for (int j = 0;j < iN;++j)
		{
			int iNum;
			cin >> iNum;
			if (iNum == 7) ++iCount;
		}
	}

	if (iCount == 3)
	{
		cout << "777" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}
