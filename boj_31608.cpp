#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	string strA, strB;
	cin >> strA >> strB;

	int iAns = 0;
	for(int i=0;i<iN;++i)
	{
		if(strA[i] != strB[i])
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
