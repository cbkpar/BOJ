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
	vector<int> vecNum(iN-1,0);
	for(int i=0;i<iN-1;++i)
	{
		cin >> vecNum[i];
	}

	for(int i=1;i<=iN;++i)
	{
		vector<int> vecTemp(iN,0);
		vector<bool> vecVisited(iN+1,false);

		vecTemp[0] = i;
		vecVisited[i] = true;

		bool bPossible = true;
		for(int j=1;j<iN;++j)
		{
			int iNext = vecNum[j-1]-vecTemp[j-1];
			if(iNext < 1 || iNext > iN)
			{
				bPossible = false;
				break;
			}
			if(vecVisited[iNext])
			{
				bPossible = false;
				break;
			}
			vecTemp[j] = iNext;
			vecVisited[iNext] = true;
		}

		if(bPossible)
		{
			for(int i=0;i<iN;++i)
			{

				cout << vecTemp[i] << (i==iN-1?"\n":" ");
			}
		}
	}

	return 0;
}
