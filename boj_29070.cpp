#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iA, iB, iW, iH;
	cin >> iA >> iB >> iW >> iH;

	int iAns = ((iW + iA - 1) / iA) * ((iH + iB - 1) / iB);
	cout << iAns << "\n";
	return 0;
}
