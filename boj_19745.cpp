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

	long long lNum;
	cin >> lNum;
	++lNum;

	stack<long long> stackNum;
	while (lNum)
	{
		stackNum.push(lNum % 10);
		lNum /= 10;
	}
	int iSize = stackNum.size() + 1;
	vector<int> vecNum(iSize, 0);
	for (int i = 1; i < iSize; ++i)
	{
		vecNum[i] = stackNum.top();
		stackNum.pop();
	}

	while (true)
	{
		bool bChanged = false;
		for (int i = 0; i < iSize - 1; ++i)
		{
			if (vecNum[i] == vecNum[i + 1])
			{
				++vecNum[i + 1];
				for (int j = i + 1; j > 0; --j)
				{
					if (vecNum[j] >= 10)
					{
						vecNum[j - 1] += vecNum[j] / 10;
						vecNum[j] %= 10;
					}
				}
				bool bZero = true;
				if (vecNum[i + 1] == 0) bZero = false;
				for (int j = i + 2; j < iSize; ++j)
				{
					vecNum[j] = (bZero ? 0 : 1);
					bZero = !bZero;
				}
				bChanged = true;
				break;
			}
		}
		if (!bChanged) break;
	}
	for (int i = 0; i < iSize; ++i)
	{
		if (vecNum[i] != 0)
		{
			for (int j = i; j < iSize; ++j)
			{
				cout << vecNum[j];
			}
			cout << "\n";
			break;
		}
	}
	return 0;
}
