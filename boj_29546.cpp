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

	vector<string> vecSrc(iN + 1, "");
	for (int i = 1; i <= iN; ++i) cin >> vecSrc[i];

	int iM;
	cin >> iM;
	while (iM--)
	{
		int iS, iE;
		cin >> iS >> iE;
		for (int i = iS; i <= iE; ++i)
		{
			cout << vecSrc[i] << "\n";
		}
	}
	return 0;
}
