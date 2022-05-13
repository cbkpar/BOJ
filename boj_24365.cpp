#include <iostream>

using namespace std;

int main()
{
	int iA, iB, iC;
	cin >> iA >> iB >> iC;
	int iM = (iA + iB + iC) / 3;
	auto MoveBee = [=](int& iFrom, int& iTo)->int {
		int iDiff = iFrom - iM;
		iTo += iDiff;
		iFrom -= iDiff;
		return iDiff > 0 ? iDiff : -iDiff;
	};
	int iAnswer = MoveBee(iA, iB) + MoveBee(iB, iC);
	cout << iAnswer << endl;
	return 0;
}
