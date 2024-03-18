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
	
	int iSum = iA + iB;

	int iDigit = 0;
	while (iSum > 0)
	{
		iDigit++;
		iSum /= 10;
	}

	cout << iDigit << "\n";
	return 0;
}
