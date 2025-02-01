#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iN;
		cin >> iN;
		vector<int> vecOdd;
		vector<int> vecOddOrder;
		vector<int> vecEven;
		vector<int> vecEvenOrder;

		for (int i = 0; i < iN; ++i)
		{
			int iNum;
			cin >> iNum;

			if (iNum % 2 == 0)
			{
				vecOdd.push_back(iNum);
				vecOddOrder.push_back(i);
			}
			else
			{
				vecEven.push_back(iNum);
				vecEvenOrder.push_back(i);
			}
		}

		sort(vecOdd.begin(), vecOdd.end());
		sort(vecEven.begin(), vecEven.end());
		sort(vecOddOrder.begin(), vecOddOrder.end());
		sort(vecEvenOrder.begin(), vecEvenOrder.end());

		vector<int> vecAns(iN, 0);
		for (int i = 0; i < vecOdd.size(); ++i)
		{
			vecAns[vecOddOrder[vecOdd.size() - i - 1]] = vecOdd[i];
		}
		for (int i = 0; i < vecEven.size(); ++i)
		{
			vecAns[vecEvenOrder[i]] = vecEven[i];
		}

		cout << "Case #" << t << ": ";
		for (int i = 0; i < iN; ++i)
		{
			cout << vecAns[i] << (i == iN - 1 ? "\n" : " ");
		}
	}

	return 0;
}
