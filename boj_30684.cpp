#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	vector<string> vecName;
	for (int i = 0;i < iN;++i)
	{
		string strName;
		cin >> strName;

		if (strName.length() == 3)
		{
			vecName.push_back(strName);
		}
	}

	sort(vecName.begin(), vecName.end());
	
	cout << vecName[0] << "\n";
	return 0;
}
