#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int vecCount[10000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 1;i <= 10000000;++i)
	{
		for (int j = i;j <= 10000000;j += i)
		{
			++vecCount[j];
		}
	}

	int iT;
	cin >> iT;
	while (iT--) 
	{
		int iL, iR;
		cin >> iL >> iR;
		int iAns = 0;
		for (int i = iL;i <= iR;++i)
		{
			iAns = max(iAns, vecCount[i]);
		}
		cout << iAns << "\n";
	}
	return 0;
}
