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

	vector<int> vecNum(46, 0);
	vector<int> vecPrev(100001, 0);

	for (int i = 1; i <= 100000; ++i)
	{
		int iTemp = i;
		int iSum = 0;
		while (iTemp)
		{
			iSum += iTemp % 10;
			iTemp /= 10;
		}
		vecPrev[i] = vecNum[iSum - 1];
		vecNum[iSum] = i;
	}

	while (true)
	{
		string strNumber;
		cin >> strNumber;
		if (strNumber == "END") break;

		int iNum = 0;
		for (char ch : strNumber)
		{
			iNum *= 10;
			iNum += ch - '0';
		}
		cout << vecPrev[iNum] << "\n";
	}
	return 0;
}
