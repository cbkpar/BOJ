#include <iostream>

using namespace std;

int main()
{
	int iX, iY, iZ;
	cin >> iX >> iY >> iZ;
	int iAnswer = [=]()->int {return (iX + iY <= iZ ? 1 : 0); }();
	cout << iAnswer << endl;
	return 0;
}
