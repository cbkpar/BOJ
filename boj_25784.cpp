#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;
	if ((iA == iB + iC) || (iB == iC + iA) || (iC == iA + iB))
	{
		cout << "1\n";
		return 0;
	}
	if ((iA == iB * iC) || (iB == iC * iA) || (iC == iA * iB))
	{
		cout << "2\n";
		return 0;
	}
	cout << "3\n";
	return 0;
}
