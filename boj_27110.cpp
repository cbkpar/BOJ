#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	int iA, iB, iC;
	cin >> iA >> iB >> iC;
	int iCount = 0;
	iCount += (iN > iA ? iA : iN);
	iCount += (iN > iB ? iB : iN);
	iCount += (iN > iC ? iC : iN);
	cout << iCount << "\n";

	return 0;
}
