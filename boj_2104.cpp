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
	vector<long long> vecNum(iN + 1);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];
	vecNum[iN] = -1;

	vector<long long> presum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) presum[i] = presum[i - 1] + vecNum[i - 1];

	long long lAns = presum[0] * presum[0];
	long long lTemp = 0;

	stack<pair<long long, long long>> stackNum;
	stackNum.push({ vecNum[0],presum[0] });
	for (int i = 1; i <= iN; ++i)
	{
		if (vecNum[i] >= stackNum.top().first)
		{
			stackNum.push({ vecNum[i],presum[i] });
		}
		else
		{
			while (!stackNum.empty() && vecNum[i] < stackNum.top().first)
			{
				pair<long long, long long> pNum = stackNum.top();
				stackNum.pop();
				lTemp = pNum.second;
				lAns = max(lAns, pNum.first * (presum[i] - lTemp));
			}
			stackNum.push({ vecNum[i],lTemp });
		}
	}
	cout << lAns << "\n";

	return 0;
}
