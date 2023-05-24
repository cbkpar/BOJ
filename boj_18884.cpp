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
	vector<string> vecFront(iN, "");
	vector<string> vecBack(iM, "");
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecFront[i];
	}
	for (int i = 0; i < iM; ++i)
	{
		cin >> vecBack[i];
	}

	int iQ;
	cin >> iQ;
	while (iQ--)
	{
		int iYear;
		cin >> iYear;
		--iYear;

		cout << vecFront[iYear % iN];
		cout << vecBack[iYear % iM];
		cout << "\n";
	}
	return 0;
}
