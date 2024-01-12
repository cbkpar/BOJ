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

	vector<int> vecNum(iN+1, 0);
	vector<int> vecOdd;
	vector<int> vecEven;
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
		if (vecNum[i] % 2 != i % 2)
		{
			if (i % 2 == 0)
			{
				vecEven.push_back(i);
			}
			else
			{
				vecOdd.push_back(i);
			}
		}
	}

	if (vecEven.size() == 1 && vecOdd.size() == 1)
	{
		cout << vecEven[0] << " " << vecOdd[0] << "\n";
	}
	else if (vecEven.size() == 0 && vecOdd.size() == 0)
	{
		if (iN == 2)
		{
			cout << "-1 -1\n";
		}
		else
		{
			cout << "1 3\n";
		}
	}
	else
	{
		cout << "-1 -1\n";
	}
	return 0;
}
