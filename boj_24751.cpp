#include <iostream>

using namespace std;

int main()
{
	double dA;
	cin >> dA;
	auto CalcRatio = [](double dPercent)->double {return (100.0 / dPercent); };
	cout << CalcRatio(dA) << endl << CalcRatio(100.0 - dA) << endl;
	return 0;
}
