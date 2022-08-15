#include <iostream>
#include <memory.h>

using namespace std;

void Hanoi(int iN, int iStart, int iDest)
{
	if (iN == 1)
	{
		cout << iStart << " " << iDest << "\n";
		return;
	}
	Hanoi(iN - 1, iStart, 6 - iStart - iDest);
	cout << iStart << " " << iDest << "\n";
	Hanoi(iN - 1, 6 - iStart - iDest, iDest);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int iN;
	cin >> iN;
	int iCount = (1 << iN) - 1;
	cout << iCount << "\n";
	Hanoi(iN, 1, 3);
	return 0;
}
