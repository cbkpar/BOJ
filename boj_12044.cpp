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
	for (int t = 1; t <= iT; ++t)
	{
		int iAns = 0;
		int iN, iK;
		cin >> iN >> iK;

		vector<vector<int>> vecNum(4, vector<int>(iN, 0));
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < iN; ++j)
			{
				cin >> vecNum[i][j];
			}
		}

		for (int i = 0; i < iN; ++i)
		{
			int iA = vecNum[0][i];
			for (int j = 0; j < iN; ++j)
			{
				int iB = iA^vecNum[1][j];
				for (int k = 0; k < iN; ++k)
				{
					int iC = iB ^ vecNum[2][k];
					for (int l = 0; l < iN; ++l)
					{
						int iD = iC ^ vecNum[3][l];
						if (iD == iK) ++iAns;
					}
				}
			}
		}
		cout << "Case #" << t << ": " << iAns << "\n";
	}
	return 0;
}
