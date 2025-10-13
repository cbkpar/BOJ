#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(11, 0);
	for(int i=0;i<11;++i)
	{
		cin >> vecNum[i];
	}

	int iN;
	cin >> iN;

	int iSum = 0;
	for(int i=0;i<iN;++i)
	{
		int iB, iS;
		double dL;
		cin >> iB >> dL >> iS;

		if(dL >= 2.0 && iS >= 17)
		{
			iSum += vecNum[iB];
		}
	}

	cout << iSum << "\n";
	return 0;
}
