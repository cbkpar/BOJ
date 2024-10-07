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
	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;

		if (iNum % 2 == 1)
		{
			++iCount;
		}
	}

	cout << iCount << "\n";
	return 0;
}
