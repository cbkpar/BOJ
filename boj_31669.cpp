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

	int iN, iM;
	cin >> iN >> iM;

	vector<string> vecSchedule(iN, "");
	for (int i = 0;i < iN;++i) cin >> vecSchedule[i];

	for (int i = 0;i < iM;++i)
	{
		bool bPossible = true;
		for (int j = 0;j < iN;++j)
		{
			if (vecSchedule[j][i] == 'O') bPossible = false;
		}
		if (bPossible)
		{
			cout << (i + 1) << "\n";
			return 0;
		}
	}

	cout << "ESCAPE FAILED" << "\n";
	return 0;
}
