#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iC, iD, iM;
		cin >> iC >> iD >> iM;

		vector<vector<int>> matMoney(iD + 1, vector<int>(iC + 1, 0));
		for (int i = 0;i < iM;++i)
		{
			int iCi, iDi, iMi;
			cin >> iDi >> iCi >> iMi;
			matMoney[iDi][iCi] += iMi;
		}

		vector<int> vecAns;
		for (int i = 1;i <= iD;++i)
		{
			int iSum = 0;
			bool bPossible = true;
			for (int j = 1;j <= iC;++j)
			{
				iSum += matMoney[i][j];
				if (matMoney[i][j] > 2100) bPossible = false;
			}
			if (iSum > 40000) bPossible = false;
			if (!bPossible)
			{
				vecAns.push_back(i);
			}
		}

		cout << "Data Set " << t << ":\n";
		if (vecAns.size() == 0)
		{
			cout << "No violations" << "\n";
		}
		else
		{
			cout << "Violators:" << "\n";
			for (int iNum : vecAns)
			{
				cout << iNum << "\n";
			}
		}
	}

	return 0;
}
