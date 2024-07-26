#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iW;
	cin >> iH >> iW;
	int iMin = min(iH, iW);
	cout << (iMin * 50) << "\n";
	return 0;
}
