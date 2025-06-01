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

	while (true)
	{
		int iN, iM;
		cin >> iN >> iM;
		if (iN == 0 && iM == 0) break;

		queue<int> qNum;
		for (int i = 1;i <= iN;++i)
		{
			qNum.push(i);
		}

		while (qNum.size() > 1)
		{
			for (int i = 0;i < iM - 1;++i)
			{
				int iNum = qNum.front();
				qNum.pop();
				qNum.push(iNum);
			}
			qNum.pop();
		}

		cout << qNum.front() << "\n";

	}

	return 0;
}
