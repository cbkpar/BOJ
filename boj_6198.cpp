#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	long long lAns = 0;

	stack<int> stHeight;
	for (int i = 0; i < iN; ++i)
	{
		int iHeight;
		cin >> iHeight;
		while (!stHeight.empty())
		{
			if (stHeight.top() > iHeight) break;
			stHeight.pop();
		}
		lAns += stHeight.size();
		stHeight.push(iHeight);
	}
	cout << lAns << "\n";

	return 0;
}
