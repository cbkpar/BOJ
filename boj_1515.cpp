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

	string strNumber;
	cin >> strNumber;

	int iAns = 0;

	int iNow = 0;
	int iSize = strNumber.size();
	while (true)
	{
		if (iNow >= iSize)
		{
			break;
		}

		int iTemp = ++iAns;
		stack<int> stackNum;
		while (iTemp)
		{
			stackNum.push(iTemp % 10);
			iTemp /= 10;
		}
		while (!stackNum.empty())
		{
			int iNum = stackNum.top();
			stackNum.pop();

			if (iNow < iSize && iNum == strNumber[iNow] - '0')
			{
				++iNow;
			}
		}
	}
	cout << iAns << "\n";
	return 0;
}
