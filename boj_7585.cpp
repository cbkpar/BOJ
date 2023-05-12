#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		string strCode;
		getline(cin, strCode);

		if (strCode == "#") break;

		stack<char> stackBraket;
		bool bPossible = true;

		int iSize = strCode.length();
		for (int i = 0; i < iSize; ++i)
		{
			if (strCode[i] == '(')
			{
				stackBraket.push('(');
			}
			if (strCode[i] == '[')
			{
				stackBraket.push('[');
			}
			if (strCode[i] == '{')
			{
				stackBraket.push('{');
			}
			if (strCode[i] == ')')
			{
				if (stackBraket.empty() || stackBraket.top() != '(')
				{
					bPossible = false;
					break;
				}
				stackBraket.pop();
			}
			if (strCode[i] == ']')
			{
				if (stackBraket.empty() || stackBraket.top() != '[')
				{
					bPossible = false;
					break;
				}
				stackBraket.pop();
			}
			if (strCode[i] == '}')
			{
				if (stackBraket.empty() || stackBraket.top() != '{')
				{
					bPossible = false;
					break;
				}
				stackBraket.pop();
			}
		}
		if (bPossible && stackBraket.size() == 0)
		{
			cout << "Legal\n";
		}
		else
		{
			cout << "Illegal\n";
		}
	}
	
	return 0;
}
