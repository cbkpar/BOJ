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

	deque<int> dNum;

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iCommand;
		cin >> iCommand;

		int iNum;

		switch (iCommand)
		{
		case 1:
			cin >> iNum;
			dNum.push_front(iNum);
			break;
		case 2:
			cin >> iNum;
			dNum.push_back(iNum);
			break;
		case 3:
			if (dNum.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << dNum.front() << "\n";
				dNum.pop_front();
			}
			break;
		case 4:
			if (dNum.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << dNum.back() << "\n";
				dNum.pop_back();
			}
			break;
		case 5:
			cout << dNum.size() << "\n";
			break;
		case 6:
			cout << (dNum.empty() ? "1" : "0") << "\n";
			break;
		case 7:
			if (dNum.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << dNum.front() << "\n";
			}
			break;
		case 8:
			if (dNum.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << dNum.back() << "\n";
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
