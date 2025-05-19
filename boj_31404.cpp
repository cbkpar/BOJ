#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <queue>

using namespace std;

int matVisited[64][64][4][2] = { 0, };
bool matCleaned[64][64] = { false, };

int dR[4] = { -1, 0, 1, 0 };
int dC[4] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iW;
	cin >> iH >> iW;

	for (int i = 0;i < iH;++i)
	{
		for (int j = 0;j < iW;++j)
		{
			matCleaned[i][j] = false;
			for (int k = 0;k < 4;++k)
			{
				matVisited[i][j][k][0] = 0;
				matVisited[i][j][k][1] = 0;
			}
		}
	}

	int iR, iC, iD;
	cin >> iR >> iC >> iD;

	vector<string> vecMapA(iH, "");
	for (int i = 0;i < iH;++i)
	{
		cin >> vecMapA[i];
	}
	vector<string> vecMapB(iH, "");
	for (int i = 0;i < iH;++i)
	{
		cin >> vecMapB[i];
	}

	int iAns = 1;
	int iCount = 1;
	int iSame = 0;

	queue<tuple<int, int, int>> qPos;
	qPos.push(make_tuple(iR, iC, iD));
	matVisited[iR][iC][iD][0] = true;
	while (!qPos.empty())
	{
		if (++iSame > iH * iW * 8) break;

		int iNowR = get<0>(qPos.front());
		int iNowC = get<1>(qPos.front());
		int iNowD = get<2>(qPos.front());
		qPos.pop();

		int iNextD = (iNowD + (matCleaned[iNowR][iNowC] ? vecMapB[iNowR][iNowC] : vecMapA[iNowR][iNowC]) - '0') % 4;
		int iNextR = iNowR + dR[iNextD];
		int iNextC = iNowC + dC[iNextD];

		matCleaned[iNowR][iNowC] = true;

		if (iNextR < 0 || iNextR > iH - 1 || iNextC < 0 || iNextC > iW - 1) continue;
		int iCleaned = matCleaned[iNextR][iNextC] ? 1 : 0;
		++iCount;
		if (!iCleaned)
		{
			iAns = iCount;
			iSame = 0;
		}
		qPos.push(make_tuple(iNextR, iNextC, iNextD));
	}

	cout << iAns << "\n";
	return 0;
}
