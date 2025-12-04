#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;
	for(int i=0;i<iN;++i)
	{
		for(int j=0;j<iN;++j)
		{
			int iNum = i*iN+j+1;
			int iCount = 0;
			for(int k=1;k<=iNum;++k)
			{
				if(iNum%k == 0)
				{
					++iCount;
				}
			}
			if(iCount > iK)
			{
				cout << ".";
			}
			else
			{
				cout << "*";
			}
		}
		cout << "\n";
	}

	return 0;
}
