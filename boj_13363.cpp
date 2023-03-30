#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	int iC = (iB - iA + 360) % 360;
	if (iC > 180) iC -= 360;

	cout << iC << "\n";
	return 0;
}
