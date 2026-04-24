#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iK, iS;
	cin >> iK >> iS;

	int iAns = (iS / iK) + (iS % iK);
	cout << iAns << "\n";
	return 0;
}
