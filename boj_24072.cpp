#include <iostream>

using namespace std;

int main()
{
	int iA, iB, iC;
	cin >> iA >> iB >> iC;
	auto CheckBetween = [](int iA, int iB, int iC) {return (iC >= iA && iC < iB) ? 1 : 0; };
	cout << CheckBetween(iA, iB, iC) << endl;
	return 0;
}
