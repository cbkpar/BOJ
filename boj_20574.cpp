#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int dR[4] = { -1,1,-1,1 };
int dC[4] = { -1,-1,1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR, iC;
	cin >> iR >> iC;

	string strPos;
	cin >> strPos;

	int iNowR = strPos[0] - 'a';
	int iNowC = strPos[1] - '1';

	set<int> setPos;
	
	for (int i = 0;i < 4;++i)
	{
		int iNextR = iNowR + dR[i] * iR;
		int iNextC = iNowC + dC[i] * iC;
		if (iNextR < 0 || iNextR > 7 || iNextC < 0 || iNextC > 7) continue;
		setPos.insert(iNextR * 10 + iNextC);
	}

	for (int i = 0;i < 4;++i)
	{
		int iNextR = iNowR + dR[i] * iC;
		int iNextC = iNowC + dC[i] * iR;
		if (iNextR < 0 || iNextR > 7 || iNextC < 0 || iNextC > 7) continue;
		setPos.insert(iNextR * 10 + iNextC);
	}

	vector<int> vecAns;
	for (int iPos : setPos)
	{
		vecAns.push_back(iPos);
	}

	sort(vecAns.begin(), vecAns.end());
	int iAns = vecAns.size();
	cout << iAns << "\n";

	if (iAns > 0)
	{
		for (int i = 0;i < iAns;++i)
		{
			cout << (char)((vecAns[i] / 10) + 'a');
			cout << (char)((vecAns[i] % 10) + '1');
			cout << (i == iAns - 1 ? "\n" : " ");
		}
	}
	return 0;
}
