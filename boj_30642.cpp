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
	string strName;
	cin >> iN >> strName >> iM;

	if (strName == "induck")
	{
		if (iM % 2 == 1) --iM;
		if (iM == 0) iM = 2;
	}
	else
	{
		if (iM % 2 == 0) --iM;
	}
	cout << iM << "\n";
	return 0;
}
