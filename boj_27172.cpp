#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecNum(iN, 0);
	vector<int> vecCount(1000001, 0);
	vector<bool> vecExist(1000001, false);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		vecNum[i] = iNum;
		vecExist[iNum] = true;
	}
	if (vecExist[1])
	{
		vecCount[1] += iN;
		for (int iNum : vecNum)
		{
			--vecCount[iNum];
		}
	}
	for (int i = 2; i * i <= 1000000; ++i)
	{
		for (int j = i * i; j <= 1000000; j += i)
		{
			if (vecExist[j])
			{
				if (vecExist[i])
				{
					--vecCount[j];
					++vecCount[i];
				}
				if (j != i * i && vecExist[j / i])
				{
					--vecCount[j];
					++vecCount[j / i];
				}
			}
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		cout << vecCount[vecNum[i]] << (i == iN - 1 ? "\n" : " ");
	}

	return 0;
}
