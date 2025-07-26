#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		string strStrat;
		cin >> strStrat;

		if (strStrat == "#")
		{
			break;
		}

		vector<vector<char>> matBoard(3, vector<char>(3, '.'));
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				matBoard[i][j] = i * 3 + j;
			}
		}

		bool bEnd = false;
		for (int i = 0; i < 9; ++i)
		{

			int iNum;
			cin >> iNum;
			--iNum;
			int iR = iNum / 3;
			int iC = iNum % 3;
			matBoard[iR][iC] = strStrat[0];

			char chAns = ' ';
			for (int t = 0; t < 3; ++t)
			{
				if (matBoard[t][0] == matBoard[t][1] && matBoard[t][1] == matBoard[t][2])
				{
					chAns = matBoard[t][0];
					bEnd = true;
				}
			}
			for (int t = 0; t < 3; ++t)
			{
				if (matBoard[0][t] == matBoard[1][t] && matBoard[1][t] == matBoard[2][t])
				{
					chAns = matBoard[0][t];
					bEnd = true;
				}
			}
			if (matBoard[0][0] == matBoard[1][1] && matBoard[1][1] == matBoard[2][2])
			{
				chAns = matBoard[0][0];
				bEnd = true;
			}
			if (matBoard[0][2] == matBoard[1][1] && matBoard[1][1] == matBoard[2][0])
			{
				chAns = matBoard[0][2];
				bEnd = true;
			}

			if (bEnd)
			{
				cout << chAns << "\n";
				break;
			}

			if (strStrat == "O")
			{
				strStrat = "X";
			}
			else
			{
				strStrat = "O";
			}
		}
		if (!bEnd)
		{
			cout << "Draw" << "\n";
		}
	}

	return 0;
}
