#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC, iD, iE, iF;
	cin >> iA >> iB >> iC >> iD >> iE >> iF;

	int iAns = 0;
	int iMax = -1;

	if (iA * 1 >= iMax)
	{
		iMax = iA;
		iAns = 1;
	}
	if (iB * 5 >= iMax)
	{
		iMax = iB * 5;
		iAns = 5;
	}
	if (iC * 10 >= iMax)
	{
		iMax = iC * 10;
		iAns = 10;
	}
	if (iD * 20 >= iMax)
	{
		iMax = iD * 20;
		iAns = 20;
	}
	if (iE * 50 >= iMax)
	{
		iMax = iE * 50;
		iAns = 50;
	}
	if (iF * 100 >= iMax)
	{
		iMax = iF * 100;
		iAns = 100;
	}

	cout << iAns << "\n";
	return 0;
}
