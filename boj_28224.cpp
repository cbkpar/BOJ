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

	int iSum = 0;
	while (iN--)
	{
		int iNum;
		cin >> iNum;
		iSum += iNum;
	}
	cout << iSum << "\n";
	return 0;
}
