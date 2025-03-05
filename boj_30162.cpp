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

	if(iN%2==1)
	{
		cout << "0" << "\n";
	}
	else
	{
		long long lAns = 1;
		for(int i=0;i<iN;i+=2)
		{
			lAns *=2;
		}
		cout << lAns << "\n";
	}

	return 0;
}
