#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecPill(101, -1);

	int iN;
	cin >> iN;
	for (int i = 0;i < iN;++i)
	{
		int iMe, iMn;
		cin >> iMe >> iMn;
		vecPill[iMe] = iMn;
	}

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iCount;
		cin >> iCount;

		bool bPossible = true;
		queue<int> qAns;
		for (int i = 0;i < iCount;++i)
		{
			int iNum;
			cin >> iNum;

			if (vecPill[iNum] == -1)
			{
				bPossible = false;
			}
			else
			{
				qAns.push(vecPill[iNum]);
			}
		}

		if (bPossible)
		{
			while (!qAns.empty())
			{
				cout << qAns.front();
				qAns.pop();
				cout << (qAns.empty() ? "\n" : " ");
			}
		}
		else
		{
			cout << "YOU DIED" << "\n";
		}
	}

	return 0;
}
