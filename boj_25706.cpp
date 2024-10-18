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

	vector<int> vecHeight(iN+1, 0);
	for(int i=1;i<=iN;++i)
	{
		cin >> vecHeight[i];
	}
	
	vector<int> vecCount(iN+1, 0);

	for(int i=iN;i>=1;--i)
	{
		vecCount[i] = 1;
		if(i+vecHeight[i]+1 <= iN)
		{
			vecCount[i] += vecCount[i+vecHeight[i]+1];
		}
	}

	for(int i=1;i<=iN;++i)
	{
		cout << vecCount[i] << (i==iN?"\n":" ");
	}
	return 0;
}
