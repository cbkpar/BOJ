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

	int iSum = 0;
	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;

		iSum += (iNum + 1) / 2;
	}

	cout << iSum << "\n";
	return 0;
}
