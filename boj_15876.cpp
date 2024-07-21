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

	vector<int> vecNum;
	stack<int> stNum;

	vecNum.push_back(0);
	for (int i = 1; i <= 10000; ++i)
	{
		int iTemp = i;
		while (iTemp > 0)
		{
			stNum.push(iTemp % 2);
			iTemp /= 2;
		}
		while (!stNum.empty())
		{
			vecNum.push_back(stNum.top());
			stNum.pop();
		}
	}

	int iN, iK;
	cin >> iN >> iK;

	for (int i = 0; i < 5; ++i)
	{
		cout << vecNum[i * iN + iK - 1] << (i == 4 ? "\n" : " ");
	}
	return 0;
}
