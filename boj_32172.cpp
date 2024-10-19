#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecNum(iN + 1, 0);
	set<int> setNum;
	setNum.insert(0);
	for (int i = 1; i <= iN; ++i)
	{
		vecNum[i] = vecNum[i - 1] - i;
		if (vecNum[i] < 0 || setNum.find(vecNum[i]) != setNum.end())
		{
			vecNum[i] = vecNum[i - 1] + i;
		}
		setNum.insert(vecNum[i]);
	}

	cout << vecNum[iN] << "\n";
	return 0;
}
