#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	set<string> setPass;
	for (int i = 0;i < iN;++i)
	{
		string strPass;
		cin >> strPass;
		setPass.insert(strPass);
	}

	int iAns = 0;
	int iM;
	cin >> iM;
	for (int i = 0;i < iM;++i)
	{
		string strPass;
		cin >> strPass;
		if (setPass.find(strPass) != setPass.end())
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
