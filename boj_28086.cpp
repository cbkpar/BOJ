#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

enum class OPERATOR
{
	PLUS = 0, MINUS = 1, MULTIPLY = 2, DIVIDE = 3, END = 4
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA = 0;
	long long lB = 0;
	OPERATOR eOper = OPERATOR::END;

	bool bFirstNum = true;
	bool bFirstDigit = true;
	bool bMinus = false;

	string strWord;
	cin >> strWord;
	for (char ch : strWord)
	{
		if (ch == '+')
		{
			if (bMinus) lA *= -1;
			bFirstDigit = true;
			bFirstNum = false;
			bMinus = false;
			eOper = OPERATOR::PLUS;
		}
		else if (ch == '-')
		{
			if (bFirstDigit)
			{
				if (bFirstNum)
				{
					bMinus = true;
				}
				else
				{
					bMinus = true;
					bFirstDigit = false;
				}
			}
			else
			{
				if (bMinus) lA *= -1;
				bFirstDigit = true;
				bFirstNum = false;
				bMinus = false;
				eOper = OPERATOR::MINUS;
			}

		}
		else if (ch == '*')
		{
			if (bMinus) lA *= -1;
			bFirstDigit = true;
			bFirstNum = false;
			bMinus = false;
			eOper = OPERATOR::MULTIPLY;
		}
		else if (ch == '/')
		{
			if (bMinus) lA *= -1;
			bFirstDigit = true;
			bFirstNum = false;
			bMinus = false;
			eOper = OPERATOR::DIVIDE;
		}
		else
		{
			if (bFirstNum)
			{
				lA *= 8;
				lA += ch - '0';
			}
			else
			{
				lB *= 8;
				lB += ch - '0';
			}
			bFirstDigit = false;
		}
	}
	if (bMinus) lB *= -1;
	long long lAns = 0;
	switch (eOper)
	{
	case OPERATOR::PLUS:
		lAns = lA + lB;
		break;
	case OPERATOR::MINUS:
		lAns = lA - lB;
		break;
	case OPERATOR::MULTIPLY:
		lAns = lA * lB;
		break;
	case OPERATOR::DIVIDE:
		if (lB == 0)
		{
			cout << "invalid" << "\n";
			return 0;
		}
		if (lA * lB < 0)
		{
			lAns = lA / lB;
			if (lA % lB != 0) --lAns;
		}
		else
		{
			lAns = lA / lB;
		}
		break;
	default:
		break;
	}

	if (lAns < 0)
	{
		cout << "-";
		lAns *= -1;
	}
	else if (lAns == 0)
	{
		cout << "0\n";
		return 0;
	}

	stack<long long> stackNum;
	while (lAns)
	{
		stackNum.push(lAns % 8);
		lAns /= 8;
	}
	while (!stackNum.empty())
	{
		cout << stackNum.top();
		stackNum.pop();
	}
	cout << "\n";
	return 0;
}
