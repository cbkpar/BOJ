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

	stack<int> stackNum;

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iCommand, iNum;
		cin >> iCommand;
		switch (iCommand)
		{
		case 1:
			cin >> iNum;
			stackNum.push(iNum);
			break;
		case 2:
			if (stackNum.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << stackNum.top() << "\n";
				stackNum.pop();
			}
			break;
		case 3:
			cout << stackNum.size() << "\n";
			break;
		case 4:
			cout << (stackNum.empty() ? "1" : "0") << "\n";
			break;
		case 5:

			if (stackNum.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << stackNum.top() << "\n";
			}
			break;
		}
	}
	return 0;
}
