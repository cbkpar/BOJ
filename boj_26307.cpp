#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iM;
	cin >> iH >> iM;

	int iAns = iH * 60 + iM - 540;
	cout << iAns << "\n";
	return 0;
}
