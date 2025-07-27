#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for(int t=1;t<=iT;++t)
	{
		int iN;
		cin >> iN;
		vector<int> vecEven;
		vector<int> vecEvenOrder;
		vector<int> vecOdd;
		vector<int> vecOddOrder;
		for (int i = 0; i < iN; ++i)
		{
			int iNum;
			cin >> iNum;
			if (iNum % 2 == 0)
			{
				vecEven.push_back(iNum);
				vecEvenOrder.push_back(i);
			}
			else
			{
				vecOdd.push_back(iNum);
				vecOddOrder.push_back(i);
			}
		}
		sort(vecOdd.begin(), vecOdd.end(), less<int>());
		sort(vecEven.begin(), vecEven.end(), greater<int>());
		vector<int> vecAns(iN, 0);
		
		int iSizeEven = vecEven.size();
		int iSizeOdd = vecOdd.size();
		for (int i = 0; i < iSizeEven; ++i)
		{
			vecAns[vecEvenOrder[i]] = vecEven[i];
		}
		for (int i = 0; i < iSizeOdd; ++i)
		{
			vecAns[vecOddOrder[i]] = vecOdd[i];
		}
		
		cout << "Case #" << t << ": ";
		for (int i = 0; i < iN; ++i)
		{
			cout << vecAns[i] << (i == iN - 1 ? "\n" : " ");
		}
	}

	return 0;
}
