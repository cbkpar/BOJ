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

	int iSTRAWBERRY = 0;
	int iBANANA = 0;
	int iLIME = 0;
	int iPLUM = 0;

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strName;
		cin >> strName;
		int iCount;
		cin >> iCount;

		if (strName == "STRAWBERRY") iSTRAWBERRY += iCount;
		if (strName == "BANANA") iBANANA += iCount;
		if (strName == "LIME") iLIME += iCount;
		if (strName == "PLUM") iPLUM += iCount;
	}

	if (iSTRAWBERRY == 5 || iBANANA == 5 || iLIME == 5 || iPLUM == 5)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
