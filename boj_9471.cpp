#include <iostream>
#include <vector>
#include <algorithm>

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
		int iTestNum, iMod;
		cin >> iTestNum >> iMod;
		int a = 1;
		int b = 1;
		int iCount = 0;
		while (true)
		{
			++iCount;
			int temp = (a + b)%iMod;
			a = b;
			b = temp;
			if (a == 1 && b == 1) break;
		}
		cout << iTestNum << " " << iCount << "\n";
	}
	return 0;
}
