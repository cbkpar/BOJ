#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool IsDiff(int iNum)
{
	set<int> setNum;
	while (iNum)
	{
		if (setNum.find(iNum % 10) != setNum.end())
		{
			return false;
		}
		setNum.insert(iNum % 10);
		iNum /= 10;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iL, iR;
	cin >> iL >> iR;

	for (int i = iL; i <= iR; ++i)
	{
		if (IsDiff(i))
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout << "-1" << "\n";
	return 0;
}
