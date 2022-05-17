#include <iostream>

using namespace std;

int main()
{
	int iN, iM, iK;
	cin >> iN >> iM >> iK;
	iM -= 1;
	iM = (iM + (iK - 3) % iN + 2 * iN) % iN;
	++iM;
	cout << iM << endl;
	return 0;
}
