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
	vector<int> vecOdd;

	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum % 2 == 1)
		{
			vecOdd.push_back(i);
		}
	}

	bool bPossible = false;
	if (vecOdd.size() % 2 == 1)
	{
		bPossible = true;
	}
	else
	{
		if (vecOdd.size() == 2 && vecOdd[0] == 0 && vecOdd[vecOdd.size() - 1] == iN - 1)
		{
		
		}
		else if (vecOdd.size() == 0 && iN == 1)
		{

		}
		else
		{
			bPossible = true;
		}
	}

	cout << (bPossible ? "1" : "0") << "\n";
	return 0;
}
