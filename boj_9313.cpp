#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{
		int iN;
		cin >> iN;
		if(iN == -1) break;

		vector<int> vecNum(32, 0);
		for(int i=0;i<31;++i)
		{
			vecNum[i] = iN%2;
			iN /= 2;
		}

		long long lAns = 0;
		for(int i=0;i<31;++i)
		{
			lAns += vecNum[i];
			lAns *= 2;
		}
		cout << lAns << "\n";
	}
	return 0;
}
