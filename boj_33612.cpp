#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iY = 2024;
	int iM = 1;
	
	iM += iN * 7;
	while (iM > 12)
	{
		iY += 1;
		iM -= 12;
	}

	cout << iY << " " << iM << "\n";
	return 0;
}
