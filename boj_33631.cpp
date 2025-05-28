#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iF, iC, iE, iB;
	cin >> iF >> iC >> iE >> iB;

	int iNF, iNC, iNE, iNB;
	cin >> iNF >> iNC >> iNE >> iNB;

	int iTotal = 0;

	int iQ;
	cin >> iQ;
	while (iQ-- > 0)
	{
		int iCommand, iAmount;
		cin >> iCommand >> iAmount;
		
		if (iCommand == 1)
		{
			bool bPossible = true;
			if (iF < iNF * iAmount) bPossible = false;
			if (iC < iNC * iAmount) bPossible = false;
			if (iE < iNE * iAmount) bPossible = false;
			if (iB < iNB * iAmount) bPossible = false;

			if (bPossible)
			{
				iTotal += iAmount;
				iF -= iNF * iAmount;
				iC -= iNC * iAmount;
				iE -= iNE * iAmount;
				iB -= iNB * iAmount;
				cout << iTotal << "\n";
			}
			else
			{
				cout << "Hello, siumii" << "\n";
			}
		}

		if (iCommand == 2)
		{
			iF += iAmount;
			cout << iF << "\n";
		}

		if (iCommand == 3)
		{
			iC += iAmount;
			cout << iC << "\n";
		}

		if (iCommand == 4)
		{
			iE += iAmount;
			cout << iE << "\n";
		}

		if (iCommand == 5)
		{
			iB += iAmount;
			cout << iB << "\n";
		}
	}

	return 0;
}
