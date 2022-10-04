#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iM;
		cin >> iN >> iM;
		int* pArrVote = new int[iN + 1];
		memset(pArrVote, 0, sizeof(int)*(iN + 1));
		for (int i = 0; i < iM; ++i)
		{
			for (int j = 1; j <= iN; ++j)
			{
				int iVote;
				cin >> iVote;
				pArrVote[j] += iVote;
			}
		}
		int iMax = -1;
		int iIndex = 0;
		for (int i = 1; i <= iN; ++i)
		{
			if (pArrVote[i] > iMax)
			{
				iMax = pArrVote[i];
				iIndex = i;
			}
		}
		cout << iIndex << "\n";
		delete[] pArrVote;
	}
	return 0;
}
