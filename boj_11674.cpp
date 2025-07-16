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

	string strPos;
	cin >> strPos;

	int iLen = strPos.length();
	long long lX = 0;
	long long lY = 0;
	for(int i=0;i<iLen;++i)
	{
		lX *= 2;
		lY *= 2;
		if(strPos[i] == '0')
		{

		}
		else if(strPos[i] == '1')
		{
			lX += 1;
		}
		else if(strPos[i] == '2')
		{
			lY += 1;
		}
		else if(strPos[i] == '3')
		{
			lX += 1;
			lY += 1;
		}
	}

	cout << iLen << " " << lX << " " << lY << "\n";
	return 0;
}
