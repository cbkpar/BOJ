#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CalcCount(int iNum)
{
	int iCount = 0;
	while (iNum)
	{
		if (iNum % 2 == 1) ++iCount;
		iNum /= 2;
	}
	return iCount;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iM;
		cin >> iN >> iM;

		int iA, iB;
		iA = iB = 0;

		for (int i = 0; i < iN; ++i)
		{
			int iNum;
			cin >> iNum;
			iA |= 1 << iNum;
		}
		for (int i = 0; i < iM; ++i)
		{
			int iNum;
			cin >> iNum;
			iB |= 1 << iNum;
		}
		int iUnion = CalcCount(iA | iB);
		int iIntersection = CalcCount(iA & iB);
		if (iUnion > iIntersection * 2)
		{
			cout << "0\n";
		}
		else
		{
			cout << "1\n";
		}
	}
	return 0;
}
