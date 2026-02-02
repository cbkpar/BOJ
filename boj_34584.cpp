#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iX, iD;
	cin >> iX >> iD;

	if (iX * 2 <= iD)
	{
		cout << "double it" << "\n";
	}
	else
	{
		cout << "take it" << "\n";
	}
	return 0;
}
