#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CheckSdoku(const vector<vector<int>>& matNum)
{
	for (int i = 0; i < 9; ++i)
	{
		vector<bool> vecVisited(10, false);
		for (int j = 0; j < 9; ++j)
		{
			if (vecVisited[matNum[i][j]]) return false;
			vecVisited[matNum[i][j]] = true;
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		vector<bool> vecVisited(10, false);
		for (int j = 0; j < 9; ++j)
		{
			if (vecVisited[matNum[j][i]]) return false;
			vecVisited[matNum[j][i]] = true;
		}
	}

	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			vector<bool> vecVisited(10, false);
			for (int p = 0; p < 3; ++p)
			{
				for (int q = 0; q < 3; ++q)
				{
					if (vecVisited[matNum[i + p][j + q]]) return false;
					vecVisited[matNum[i + p][j + q]] = true;
				}
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;

	for (int t = 1; t <= iT; ++t)
	{
		vector<vector<int>> matNum(9, vector<int>(9, 0));
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				cin >> matNum[i][j];
			}
		}
		cout << "Case " << t << ": " << (CheckSdoku(matNum) ? "CORRECT" : "INCORRECT") << "\n";
	}
	return 0;
}
