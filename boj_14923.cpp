#include <iostream>
#include <queue>
#include <memory.h>

struct tagPos
{
	tagPos(int _iR, int _iC, int _iSkill) { iR = _iR; iC = _iC; iSkill = _iSkill; }
	int iR, iC;
	int iSkill;
};

using namespace std;

bool matWall[1000][1000];
bool matVisited[1000][1000][2];

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	int iSR, iSC, iER, iEC;
	cin >> iSR >> iSC >> iER >> iEC;
	--iSR; --iSC; --iER; --iEC;
	memset(matWall, false, sizeof(bool) * 1000000);
	memset(matVisited, false, sizeof(bool) * 2000000);

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			int iNumber;
			cin >> iNumber;
			if (iNumber == 1)
			{
				matWall[i][j] = true;
			}
		}
	}
	int iCount = 0;
	queue<tagPos> qPos;
	qPos.emplace(tagPos(iSR, iSC, 0));
	matVisited[iSR][iSC][0] = true;
	while (!qPos.empty())
	{
		int iSize = qPos.size();
		while (iSize--)
		{
			tagPos tPos = qPos.front();
			qPos.pop();

			if (tPos.iR == iER && tPos.iC == iEC)
			{
				cout << iCount << "\n";
				return 0;
			}

			for (int i = 0; i < 4; ++i)
			{
				int iNextR = tPos.iR + dR[i];
				int iNextC = tPos.iC + dC[i];
				if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1)
				{
					continue;
				}
				if (matVisited[iNextR][iNextC][tPos.iSkill])
				{
					continue;
				}
				if (matWall[iNextR][iNextC])
				{
					if (tPos.iSkill == 0)
					{
						matVisited[iNextR][iNextC][1] = true;
						qPos.emplace(tagPos(iNextR, iNextC, 1));
					}
				}
				else
				{
					matVisited[iNextR][iNextC][tPos.iSkill] = true;
					qPos.emplace(tagPos(iNextR, iNextC, tPos.iSkill));
				}
			}
		}
		++iCount;
	}
	cout << "-1\n";
	return 0;
}
