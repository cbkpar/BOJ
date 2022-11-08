#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<int> qArrNode[100000];
bool arrVisited[100001] = { false, };
int arrCount[100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	for (int i = 0; i < iN - 1; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		qArrNode[iS].emplace(iE);
	}
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrCount[i];
	}

	int iCount = arrCount[0];
	queue<int> qNode;
	qNode.emplace(0);
	arrVisited[0] = true;
	while (iK--)
	{
		int iSize = qNode.size();
		while (iSize--)
		{
			int iNumber = qNode.front();
			qNode.pop();
			while (!qArrNode[iNumber].empty())
			{
				int iNext = qArrNode[iNumber].front();
				qArrNode[iNumber].pop();
				if (!arrVisited[iNext])
				{
					qNode.emplace(iNext);
					arrVisited[iNext] = true;
					iCount += arrCount[iNext];
				}
			}
		}
	}
	cout << iCount << "\n";
	return 0;
}
