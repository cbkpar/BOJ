#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;
	for (int i = 0;i < iK;++i)
	{
		int iCount;
		cin >> iCount;

		if (iN - iCount < iCount - 1)
		{
			cout << iN;
		}
		else
		{
			cout << "1";
		}
		cout << (i == iK - 1 ? "\n" : " ");
	}

	return 0;
}
