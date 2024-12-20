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

	int iN;
	cin >> iN;

	int iMax = -1;
	vector<int> vecAns;
	
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;

		if (iNum > iMax)
		{
			iMax = iNum;
			vecAns.push_back(iNum);
		}
	}

	int iSize = vecAns.size();
	cout << iSize << "\n";

	for (int i = 0; i < iSize; ++i)
	{
		cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
	}
	return 0;
}
