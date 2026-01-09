#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		string strNum;
		cin >> strNum;
		int iSize = strNum.length();
		vector<int> vecNum;
		for (int i = 0;i < iSize;++i)
		{
			vecNum.push_back(strNum[i] - '0');
		}

		cout << "Case #" << t << ": ";

		bool bInc = true;
		for (int i = iSize - 1;i > 0;--i)
		{
			if (vecNum[i - 1] < vecNum[i])
			{
				sort(vecNum.begin() + i, vecNum.end());
				for (int j = i;j < iSize;++j)
				{
					if (vecNum[i - 1] < vecNum[j])
					{
						swap(vecNum[i - 1], vecNum[j]);
						break;
					}
				}
				sort(vecNum.begin() + i, vecNum.end());
				bInc = false;
				break;
			}
		}
		if (bInc)
		{
			++iSize;
			vecNum.push_back(0);
			sort(vecNum.begin(), vecNum.end());
			for (int i = 1;i < iSize;++i)
			{
				if (vecNum[i] > 0)
				{
					swap(vecNum[i], vecNum[0]);
					break;
				}
			}
		}
		for (int i = 0;i < iSize;++i)
		{
			cout << vecNum[i];
		}
		cout << "\n";

	}
	return 0;
}
