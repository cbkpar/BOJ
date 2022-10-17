#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	string strCode;
	cin >> strWord >> strCode;

	stack<char> stackChar;
	stack<char> stackReverse;
	stack<int> stackNum;

	int iWordLen = strWord.length();
	int iCodeLen = strCode.length();

	for (int i = 0; i < iWordLen; ++i)
	{
		if (stackChar.empty())
		{
			stackChar.push(strWord[i]);
			if (strWord[i] == strCode[0])
			{
				stackNum.push(1);
			}
			else
			{
				stackNum.push(0);
			}
		}
		else
		{
			stackChar.push(strWord[i]);
			if (strWord[i] == strCode[stackNum.top()])
			{
				stackNum.push(stackNum.top() + 1);
			}
			else
			{
				if (strWord[i] == strCode[0])
				{
					stackNum.push(1);
				}
				else
				{
					stackNum.push(0);
				}
			}
		}
		if (!stackNum.empty() && stackNum.top() == iCodeLen)
		{
			for (int i = 0; i < iCodeLen; ++i)
			{
				stackChar.pop();
				stackNum.pop();
			}
		}
	}
	while (!stackChar.empty())
	{
		stackReverse.push(stackChar.top());
		stackChar.pop();
	}
	if (stackReverse.empty())
	{
		cout << "FRULA\n";
	}
	else
	{
		while (!stackReverse.empty())
		{
			cout << stackReverse.top();
			stackReverse.pop();
		}
		cout << "\n";
	}
	return 0;
}
