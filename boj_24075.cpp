#include <iostream>

using namespace std;

int main()
{
	int iA, iB;
	cin >> iA >> iB;
	auto Abs = [](int iN) {return iN > 0 ? iN : -iN; };
	cout << iA + Abs(iB) << endl;
	cout << iA - Abs(iB) << endl;
	return 0;
}
