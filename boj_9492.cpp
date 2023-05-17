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
		int iN;
		cin >> iN;
		if (iN == 0) break;

		queue<string> queueWord;
		queue<string> queueWord2;
		for (int i = 0; i < iN; ++i)
		{
			string strWord;
			cin >> strWord;
			if (i < (iN + 1) / 2)
			{
				queueWord.push(strWord);
			}
			else
			{
				queueWord2.push(strWord);
			}
		}
		while (true)
		{
			if (queueWord.empty() && queueWord2.empty()) break;
			if (!queueWord.empty())
			{
				cout << queueWord.front() << "\n";
				queueWord.pop();
			}
			if (!queueWord2.empty())
			{
				cout << queueWord2.front() << "\n";
				queueWord2.pop();
			}
		}
	}
	return 0;
}
