#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

bitset<33554433> bCheck;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bCheck.reset();
	bool bFirst = true;

	int iNum;
	while (cin >> iNum)
	{
		if (!bCheck[iNum])
		{
			bCheck[iNum].flip();
			cout << (bFirst ? "" : " ") << iNum;
		}
		bFirst = false;
	}
	cout << "\n";
	return 0;
}
