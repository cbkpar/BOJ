#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dR[8] = { -2,-2,-1,1,2,2,1,-1 };
int dC[8] = { -1,1,2,2,1,-1,-2,-2 };

string RetPos(int iR, int iC)
{
	string strPos = "a1";
	strPos[0] = (char)(iR + 'a');
	strPos[1] = (char)(iC + '1');
	return strPos;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	string strPos;
	cin >> strPos;

	int iR = strPos[0] - 'a';
	int iC = strPos[1] - '1';

	vector<string> vecAns;

	for (int i = 0;i < 8;++i)
	{
		int iNextR = iR + dR[i];
		int iNextC = iC + dC[i];
		if (iNextR >= 0 && iNextR <= 7 && iNextC >= 0 && iNextC <= 7)
		{
			vecAns.push_back(RetPos(iNextR, iNextC));
		}
	}
	sort(vecAns.begin(), vecAns.end());

	for (const string& strAns : vecAns)
	{
		cout << strAns << "\n";
	}

	return 0;
}
