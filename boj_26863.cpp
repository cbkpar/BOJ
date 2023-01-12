#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC, iD, iPlus;
	cin >> iA >> iB >> iC >> iD >> iPlus;

	if (iA == iB && iB == iC && iC == iD)
	{
		cout << "1\n";
	}
	else if (iA + iPlus == iB && iB == iC && iC == iD)
	{
		cout << "1\n";
	}
	else if (iA == iB + iPlus && iB + iPlus == iC && iC == iD)
	{
		cout << "1\n";
	}
	else if (iA == iB && iB == iC + iPlus && iC + iPlus == iD)
	{
		cout << "1\n";
	}
	else if (iA == iB && iB == iC && iC == iD + iPlus)
	{
		cout << "1\n";
	}
	else
	{
		cout << "0\n";
	}

	return 0;
}
