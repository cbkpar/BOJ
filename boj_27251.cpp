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
	for (int i = 1;i <= iN;++i)
	{
		int iTotal = i * i;
		int iCount = min(iTotal, 100);
		for (int j = 0;j < iCount;++j)
		{
			cout << "*";
		}
		if (iTotal > 100)
		{
			cout << "...";
		}
		cout << "\n";
	}

	
	return 0;
}
