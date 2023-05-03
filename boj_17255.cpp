#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>

using namespace std;

typedef struct tagNumber
{
	int iLeft;
	int iRight;
	string strNum;
	string strSum;
}NUMBER;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strNum;
	cin >> strNum;

	set<string> setAns;
	queue<NUMBER> qNum;

	int iSize = strNum.length();
	for (int i = 0; i < iSize; ++i)
	{
		NUMBER tNum;
		tNum.iLeft = i;
		tNum.iRight = i;
		tNum.strNum = strNum[i];
		tNum.strSum = strNum[i];
		qNum.push(tNum);
	}
	while (!qNum.empty())
	{
		NUMBER tNum = qNum.front();
		qNum.pop();
		if (tNum.iLeft == 0 && tNum.iRight == iSize - 1)
		{
			setAns.insert(tNum.strSum);
		}
		if (tNum.iLeft > 0)
		{
			string strTemp = strNum[tNum.iLeft - 1] + tNum.strNum;
			string strNext = tNum.strSum + strTemp;

			NUMBER tempNum;
			tempNum.iLeft = tNum.iLeft - 1;
			tempNum.iRight = tNum.iRight;
			tempNum.strNum = strTemp;
			tempNum.strSum = strNext;
			qNum.push(tempNum);
		}
		if (tNum.iRight < iSize - 1)
		{
			string strTemp = tNum.strNum + strNum[tNum.iRight + 1];
			string strNext = tNum.strSum + strTemp;

			NUMBER tempNum;
			tempNum.iLeft = tNum.iLeft;
			tempNum.iRight = tNum.iRight + 1;
			tempNum.strNum = strTemp;
			tempNum.strSum = strNext;
			qNum.push(tempNum);
		}
	}

	cout << setAns.size() << "\n";
	return 0;
}
