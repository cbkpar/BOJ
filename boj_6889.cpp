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

	vector<string> vecAdj(iN, "");
	vector<string> vecNoun(iM, "");

	for (int i = 0; i < iN; ++i)
	{
		cin >> vecAdj[i];
	}
	for (int i = 0; i < iM; ++i)
	{
		cin >> vecNoun[i];
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cout << vecAdj[i] << " as " << vecNoun[j] << "\n";
		}
	}
	return 0;
}
