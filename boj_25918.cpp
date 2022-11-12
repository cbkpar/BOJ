#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	string str;
	cin >> str;
	stack<int> stackNumber;
	
	int iAns = 0;

	for (int i = 0; i < iN; ++i)
	{
		if (str[i] == '(')
		{
			if (stackNumber.empty())
			{
				stackNumber.emplace(0);
			}
			else
			{
				if (stackNumber.top() == 0)
				{
					stackNumber.emplace(0);
				}
				else
				{
					stackNumber.pop();
				}
			}
		}
		else
		{
			if (stackNumber.empty())
			{
				stackNumber.emplace(1);
			}
			else
			{
				if (stackNumber.top() == 1)
				{
					stackNumber.emplace(1);
				}
				else
				{
					stackNumber.pop();
				}
			}

		}
		if (stackNumber.size() > iAns)
		{
			iAns = stackNumber.size();
		}
	}
	if (stackNumber.empty())
	{
		cout << iAns << "\n";
	}
	else
	{
		cout << "-1\n";
	}
	return 0;
}
