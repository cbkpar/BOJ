#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR, iF;
	cin >> iR >> iF;

	iF %= (iR * 2);
	int iDegree = iF * 180 / iR;
	if (iDegree < 90 || iDegree >= 270)
	{
		cout << "up\n";
	}
	else
	{
		cout << "down\n";
	}
	return 0;
}
