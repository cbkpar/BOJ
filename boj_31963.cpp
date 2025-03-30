#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<long long> vecNum1(iN, 0);
	vector<double> vecNum2(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		vecNum1[i] = (int)log2(iNum);
		vecNum2[i] = log2(iNum)-vecNum1[i];
	}

	long long lAns = 0;
	for (int i = 1; i < iN; ++i)
	{
		if (vecNum1[i] > vecNum1[i-1])
		{

		}
		else if (vecNum1[i] == vecNum1[i - 1])
		{
			if (vecNum2[i] < vecNum2[i - 1])
			{
				++lAns;
				vecNum1[i]++;
			}
		}
		else
		{
			lAns += vecNum1[i - 1] - vecNum1[i];
			vecNum1[i] = vecNum1[i-1];
			if (vecNum2[i] < vecNum2[i - 1])
			{
				++lAns;
				vecNum1[i]++;
			}
		}
	}

	cout << lAns << "\n";
	return 0;
}
