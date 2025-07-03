#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<vector<int>> matNum(iN + 1, vector<int>(iN + 1, 0));
	for (int i = 1;i <= iN;++i)
	{
		for (int j = 1;j <= iN;++j)
		{
			cin >> matNum[i][j];
		}
	}

	int iQ;
	cin >> iQ;
	while (iQ-- > 0)
	{
		int iCommand;
		cin >> iCommand;

		if(iCommand == 1)
		{
			int iLine;
			cin >> iLine;
			
			int iTemp = matNum[iLine][iN];
			for (int i = iN;i > 1;--i)
			{
				matNum[iLine][i] = matNum[iLine][i - 1];
			}
			matNum[iLine][1] = iTemp;
		}
		else
		{
			vector<vector<int>> matTemp(iN + 1, vector<int>(iN + 1, 0));
			for (int i = 1;i <= iN;++i)
			{
				for (int j = 1;j <= iN;++j)
				{
					matTemp[j][iN - i + 1] = matNum[i][j];
				}
			}
			for (int i = 1;i <= iN;++i)
			{
				for (int j = 1;j <= iN;++j)
				{
					matNum[i][j] = matTemp[i][j];
				}
			}
		}
	}

	for (int i = 1;i <= iN;++i)
	{
		for (int j = 1;j <= iN;++j)
		{
			cout << matNum[i][j] << (j == iN ? "\n" : " ");
		}
	}

	return 0;
}
