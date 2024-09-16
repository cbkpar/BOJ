#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA;
	cin >> iA;

	int iW, iV;
	cin >> iW >> iV;

	if (iW / iV >= iA)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}

	return 0;
}
