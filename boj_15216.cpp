#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iW, iN;
	cin >> iH >> iW >> iN;

	int iNowH = 0;
	int iNowW = 0;

	for (int i = 0;i < iN;++i)
	{
		int iX;
		cin >> iX;
		iNowW += iX;
		if (iNowW == iW)
		{
			++iNowH;
			iNowW = 0;
		}
		else if (iNowW > iW)
		{
			break;
		}
	}

	if (iNowH >= iH)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}
