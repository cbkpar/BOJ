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

	cin.ignore();
	vector<string> vecRule(iN + 1, "");
	for (int i = 1; i <= iN; ++i) getline(cin, vecRule[i]);

	int iM;
	cin >> iM;
	while (iM--)
	{
		int iNum;
		cin >> iNum;
		if (iNum >= 1 && iNum <= iN)
		{
			cout << "Rule " << iNum << ": " << vecRule[iNum] << "\n";
		}
		else
		{
			cout << "Rule " << iNum << ": No such rule" << "\n";
		}
	}

	return 0;
}
