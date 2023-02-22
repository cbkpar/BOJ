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

	int iM;
	cin >> iM;

	if (iM != iN - 1)
	{
		cout << "No\n";
		return 0;
	}
	int iTemp = iN;
	for (int i = 1; i <= iM; ++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum == i + (iTemp != iN? 1 : 0)) continue;
		if (iTemp == iN && iNum == i + 1)
		{
			iTemp = i;
		}
		else
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	cout << iTemp << "\n";
	return 0;
}
