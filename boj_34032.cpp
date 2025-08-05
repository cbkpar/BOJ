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

	int iCount = 0;
	string strResult;
	cin >> strResult;
	for(int i=0;i<iN;++i)
	{
		if(strResult[i] == 'O')
		{
			++iCount;
		}
	}

	if(iCount*2 >= iN)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}

	return 0;
}
