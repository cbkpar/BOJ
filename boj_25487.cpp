#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iA, iB, iC;
		cin >> iA >> iB >> iC;
		int iAns = iA;
		if (iB < iAns) iAns = iB;
		if (iC < iAns) iAns = iC;
		cout << iAns << "\n";
	}
	return 0;
}
