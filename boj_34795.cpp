#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iM, iD;
	cin >> iM >> iD;

	int iAns = (iD + iM - 1) / iM;
	cout << iAns << "\n";

	return 0;
}
