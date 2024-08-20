#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iDay;
	cin >> iDay;

	bool bTuesday = false;
	if ((iDay + 5) % 7 == 0)
	{
		bTuesday = true;
	}

	cout << (bTuesday ? 1 : 0) << "\n";
	return 0;
}
