#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string vecMonth[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT = 0;
	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;
		++iT;

		vector<int> vecCount(13, 0);

		for (int i = 0;i < iN;++i)
		{
			string strDay, strMonth, strYear;
			cin >> strDay >> strMonth >> strYear;
			int iMonth = (strMonth[0] - '0') * 10 + (strMonth[1] - '0');
			++vecCount[iMonth];
		}

		cout << "Case #" << iT << ":\n";
		for (int i = 1;i <= 12;++i)
		{
			cout << vecMonth[i] << ":";
			for (int j = 0;j < vecCount[i];++j)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}

	return 0;
}
