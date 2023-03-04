#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	set<int> setNum;

	int iAns = 0;

	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum < 0)
		{
			if (setNum.find(abs(iNum)) == setNum.end())
			{
				++iAns;
			}
		}
		else
		{
			setNum.insert(iNum);
		}
	}
	cout << iAns << "\n";

	return 0;
}
