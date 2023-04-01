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

	while (true)
	{
		int iN;
		cin >> iN;

		if (iN == 0) break;

		vector<string> vecAns;

		float fMax = -1.f;

		for (int i = 0; i < iN; ++i)
		{
			string strName;
			float fSpeed;
			cin >> strName >> fSpeed;
			if (fSpeed > fMax)
			{
				vecAns.clear();
				fMax = fSpeed;
				vecAns.push_back(strName);
			}
			else if (fSpeed == fMax)
			{
				vecAns.push_back(strName);
			}
		}
		int iSize = vecAns.size();
		for (int i = 0; i < iSize; ++i)
		{
			cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
		}
	}
	return 0;
}
