#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iR0, iW0, iC, iR;
		cin >> iR0 >> iW0 >> iC >> iR;
		if (iR0 == 0 && iW0 == 0 && iC == 0 && iR == 0) break;
		
		int iAns = (iW0 * iC - iR0 + iR - 1) / iR;
		if (iAns < 0) iAns = 0;
		cout << iAns << "\n";
	}

	return 0;
}
