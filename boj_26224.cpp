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

	string strName1, strName2;
	string strTemp;
	long long lA, lB, lC;
	cin >> strName1 >> lA >> strName2 >> strTemp >> lC;

	lB = 0;
	int iLen = strTemp.length();
	for (int i = 0;i < iLen;++i)
	{
		if (strTemp[i] == '.')
		{
			for (int j = i + 1;j < iLen;++j)
			{
				lB *= 10;
				lC *= 10;
				lB += strTemp[j] - '0';
			}
			break;
		}
		else
		{
			lB *= 10;
			lB += strTemp[i] - '0';
		}
	}

	if (lA * lB > lC)
	{
		cout << "Power up, Evolve" << "\n";
	}
	else if (lA * lB == lC)
	{
		cout << "Whatever" << "\n";
	}
	else
	{
		cout << "Evolve, Power up" << "\n";
	}

	return 0;
}
