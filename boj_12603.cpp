#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for(int t=1;t<=iT;++t)
	{
		int iC;
		cin >> iC;

		int iP;
		cin >> iP;
		vector<int> vecP(iP, 0);
		for(int i=0;i<iP;++i) 
		{
			cin >> vecP[i];
		}

		for(int i=0;i<iP;++i)
		{
			for(int j=i+1;j<iP;++j)
			{
				if(vecP[i]+vecP[j] == iC)
				{
					cout << "Case #" << t <<": " << (i+1) << " " << (j+1) << "\n";
					i = iP;
					j = iP;
				}
			}
		}
	}

	return 0;
}
