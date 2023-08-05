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
		int iG, iC, iE;
		cin >> iG >> iC >> iE;
		if (iE <= iC)
		{
			cout << "0\n";
		}
		else
		{
			cout << (iE - iC) * (iG * 2 - 1) << "\n";
		}
	}
	return 0;
}
