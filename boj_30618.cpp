#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	vector<int> vecNum(iN, 0);

	bool bLeft = true;
	int iLeft = 0;
	int iRight = iN - 1;
	for (int i = 1;i <= iN;++i)
	{
		if (bLeft)
		{
			vecNum[iLeft++] = i;
		}
		else
		{
			vecNum[iRight--] = i;
		}
		bLeft = !bLeft;
	}

	for (int i = 0;i < iN;++i)
	{
		cout << vecNum[i] << (i == iN - 1 ? "\n" : " ");
	}
	return 0;
}
