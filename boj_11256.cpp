#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iTest;
	cin >> iTest;
	while (iTest--)
	{
		int iCandy, iN;
		cin >> iCandy >> iN;
		vector<int> vecCapacity;
		vecCapacity.reserve(iN);
		for (int i = 0; i < iN; ++i)
		{
			int iR, iC;
			cin >> iR >> iC;
			vecCapacity.push_back(iR*iC);
		}
		sort(vecCapacity.begin(), vecCapacity.end());
		int iCount = 0;
		for (int i = iN - 1; i >= 0; i--)
		{
			iCandy -= vecCapacity[i];
			++iCount;
			if (iCandy <= 0)
			{
				break;
			}
		}
		cout << iCount << "\n";
	}
	return 0;
}
