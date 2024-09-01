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

	int iWin = iA/3;
	int iDraw = 0;
	int iLoss = iB/3;

	iA %= 3;
	iB %= 3;

	if(iA != iB)
	{
		cout << "-1";
		return 0;
	}

	iDraw = iA;

	cout << iWin << " ";
	cout << iDraw << " ";
	cout << iLoss << "\n";

	return 0;
}
