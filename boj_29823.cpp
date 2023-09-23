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

	pair<int, int> pPos = { 0,0 };

	int iN;
	cin >> iN;

	string strMove;
	cin >> strMove;

	for (char ch : strMove)
	{
		if (ch == 'N') ++pPos.first;
		if (ch == 'E') ++pPos.second;
		if (ch == 'W') --pPos.second;
		if (ch == 'S') --pPos.first;
	}
	cout << (abs(pPos.first) + abs(pPos.second)) << "\n";
	return 0;
}
