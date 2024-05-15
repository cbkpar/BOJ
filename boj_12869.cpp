#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dp[61][61][61] = {0,};
int attack[6][3] = {{1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1}};

struct tPos
{
	int iX;
	int iY;
	int iZ;

	tPos(int _iX, int _iY, int _iZ)
	{
		iX = _iX;
		iY = _iY;
		iZ = _iZ;
	}
};

int main()
{
	int iN;
	cin >> iN;

	vector<int> vecHp(3, 0);
	for(int i=0;i<iN;++i)
	{
		cin >> vecHp[i];
	}
	for(int i=0;i<=vecHp[0];++i)
	{
		for(int j=0;j<=vecHp[1];++j)
		{
			for(int k=0;k<=vecHp[2];++k)
			{
				dp[i][j][k] = 1000000000;
			}
		}
	}

	queue<tPos> qPos;
	qPos.push(tPos(vecHp[0], vecHp[1], vecHp[2]));
	dp[vecHp[0]][vecHp[1]][vecHp[2]] = 0;

	int iCount = 0;
	while(!qPos.empty())
	{
		int iSize = qPos.size();
		++iCount;
		while(iSize--)
		{
			tPos pos = qPos.front();
			qPos.pop();

			for(int i=0;i<6;++i)
			{
				int iNextX = pos.iX - attack[i][0];
				int iNextY = pos.iY - attack[i][1];
				int iNextZ = pos.iZ - attack[i][2];
				if(iNextX < 0) iNextX = 0;
				if(iNextY < 0) iNextY = 0;
				if(iNextZ < 0) iNextZ = 0;

				if(dp[iNextX][iNextY][iNextZ] != 1000000000) continue;

				dp[iNextX][iNextY][iNextZ] = iCount;
				qPos.push(tPos(iNextX, iNextY, iNextZ));
			}
		}
	}
	
	cout << dp[0][0][0] << "\n";
	return 0;
}
