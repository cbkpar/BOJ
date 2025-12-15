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
		int iN, iK;
		cin >> iN >> iK;
		vector<int> vecNum(iK, 0);
		for(int i=0;i<iN;++i)
		{
			int iNum;
			cin >> iNum;
			vecNum[iNum%iK]++;
		}

		int iAns = vecNum[0];
		if(iK==2)
		{
			iAns += (vecNum[1]+1)/2;
		}
		else if(iK==3)
		{
			if(vecNum[1]>=vecNum[2])
			{
				iAns += vecNum[2];
				vecNum[1] -= vecNum[2];
				iAns += (vecNum[1]+2)/3;
			}
			else
			{
				iAns += vecNum[1];
				vecNum[2] -= vecNum[1];
				iAns += (vecNum[2]+2)/3;
			}
		}

		cout << "Case #" << t <<": "<<iAns << "\n";
	}

	return 0;
}
