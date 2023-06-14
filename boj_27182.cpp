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

	iA -= 7;
	iB += 7;
	if (iA > 0)
	{
		cout << iA << "\n";
	}
	else
	{
		cout << iB << "\n";
	}
	return 0;
}
