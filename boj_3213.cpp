#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	int iCountA = 0;
	int iCountB = 0;
	int iCountC = 0;
	for (int i = 0; i < iN; ++i)
	{
		string strInput;
		cin >> strInput;

		if (strInput == "1/4")
		{
			++iCountA;
		}
		else if (strInput == "1/2")
		{
			++iCountB;
		}
		else if (strInput == "3/4")
		{
			++iCountC;
		}
	}
	int iAns = 0;
	iAns += iCountC;
	iCountA -= iCountC;
	if (iCountA < 0)
	{
		iCountA = 0;
	}
	iAns += (iCountA + 2 * iCountB + 3) / 4;
	cout << iAns << "\n";
	return 0;
}
