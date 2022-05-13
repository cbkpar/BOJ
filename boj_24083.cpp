#include <iostream>

using namespace std;

int main()
{
	int iA, iB;
	cin >> iA >> iB;
	int iAnswer = [](int iHour, int iPlus)->int {return (iHour + iPlus - 1) % 12 + 1; }(iA, iB);
	cout << iAnswer << endl;
	return 0;
}
