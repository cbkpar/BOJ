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

	int iT;
	cin >> iT;
	for (int t = 0;t < iT;++t)
	{
		if (t != 0) cout << "\n";

		int iA, iB, iC;
		cin >> iA >> iB >> iC;
		vector<string> vecA(iA, "");
		cin.ignore();
		for (int i = 0;i < iA;++i)
		{
			getline(cin, vecA[i]);
		}
		vector<string> vecB(iB, "");
		for (int i = 0;i < iB;++i)
		{
			getline(cin, vecB[i]);
		}
		vector<string> vecC(iC, "");
		for (int i = 0;i < iC;++i)
		{
			getline(cin, vecC[i]);
		}

		for (int i = 0;i < iA;++i)
		{
			for (int j = 0;j < iB;++j)
			{
				for (int k = 0;k < iC;++k)
				{
					cout << vecA[i] << " " << vecB[j] << " " << vecC[k] << "." << "\n";
				}
			}
		}
	}

	return 0;
}
