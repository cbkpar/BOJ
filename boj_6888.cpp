#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iS, iE;
	cin >> iS >> iE;
	for (int i = iS; i <= iE; i += 60)
	{
		cout << "All positions change in year " << i << "\n";
	}
	return 0;
}
