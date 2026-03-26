#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	vector<vector<int>> vecHeight(11, vector<int>(11, 1));

	int iK;
	cin >> iK;
	while (iK-- > 0)
	{
		for (int i = 1;i <= 10;++i)
		{
			for (int j = 1;j <= 10;++j)
			{
				vecHeight[i][j]++;
			}
		}

		for (int i = 0;i < 3;++i)
		{
			int iR;
			cin >> iR;
			for (int j = 1;j <= 10;++j)
			{
				vecHeight[iR][j] = 1;
			}
		}
		for (int i = 0;i < 3;++i)
		{
			int iC;
			cin >> iC;
			for (int j = 1;j <= 10;++j)
			{
				vecHeight[j][iC] = 1;
			}
		}
	}

	for (int i = 1;i <= 10;++i)
	{
		for (int j = 1;j <= 10;++j)
		{
			cout << vecHeight[i][j] << (j == 10 ? "\n" : " ");
		}
	}
	return 0;
}
