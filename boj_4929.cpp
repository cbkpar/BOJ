#include <iostream>

using namespace std;

int arrN[10001] = { 0, };
int arrM[10001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iM;
		cin >> iN;
		if (iN == 0)
		{
			break;
		}
		for (int i = 0; i < iN; ++i)
		{
			cin >> arrN[i];
		}
		cin >> iM;
		for (int i = 0; i < iM; ++i)
		{
			cin >> arrM[i];
		}
		int iSum = 0;
		int iSumN = 0;
		int iSumM = 0;
		bool bIsN = false;
		int iLeftN = 0;
		int iLeftM = 0;
		while (true)
		{
			if (iLeftN == iN)
			{
				while (iLeftM < iM)
				{
					iSumM += arrM[iLeftM++];
				}
				break;
			}
			if (iLeftM == iM)
			{
				while (iLeftN < iN)
				{
					iSumN += arrN[iLeftN++];
				}
				break;
			}
			if (arrN[iLeftN] == arrM[iLeftM])
			{
				iSum += (iSumN > iSumM ? iSumN : iSumM) + arrN[iLeftN];
				++iLeftN;
				++iLeftM;
				iSumN = 0;
				iSumM = 0;
			}
			else if (arrN[iLeftN] > arrM[iLeftM])
			{
				iSumM += arrM[iLeftM++];
			}
			else
			{
				iSumN += arrN[iLeftN++];
			}
		}
		iSum += (iSumN > iSumM ? iSumN : iSumM);
		cout << iSum << "\n";
	}
	return 0;
}
