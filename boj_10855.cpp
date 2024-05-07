#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	vector<int> vecNum(iN,0);
	for(int i=0;i<iN;++i)
	{
		cin >> vecNum[i];
	}

	bool bPossible = true;
	for(int i=1;i<iN;++i)
	{
		if(vecNum[i-1] > vecNum[i])
		{
			bPossible = false;
		}
	}

	cout << (bPossible?"yes":"no") << "\n";
	return 0;
}
