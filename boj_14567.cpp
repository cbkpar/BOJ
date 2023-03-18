#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> vecNode[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	vector<int> vecCount(iN + 1, 0);
	vector<int> vecAns(iN + 1, 0);

	while (iM--)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecNode[iS].push_back(iE);
		++vecCount[iE];
	}

	int iCount = 1;
	queue<int> qSubject;
	for (int i = 1; i <= iN; ++i)
	{
		if (vecCount[i] == 0)
		{
			qSubject.push(i);
			vecAns[i] = iCount;
		}
	}

	while (!qSubject.empty())
	{
		++iCount;
		int iSize = qSubject.size();
		while (iSize--)
		{
			int iNow = qSubject.front();
			qSubject.pop();
			for (int iNext : vecNode[iNow])
			{
				if (--vecCount[iNext] == 0)
				{
					qSubject.push(iNext);
					vecAns[iNext] = iCount;
				}
			}
		}
	}

	for (int i = 1; i <= iN; ++i)
	{
		cout << vecAns[i] << (i == iN ? "\n" : " ");
	}
	return 0;
}
