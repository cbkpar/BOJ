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

	int iN, iM, iK, iA, iB, iC;
	cin >> iN >> iM >> iK >> iA >> iB >> iC;

	int iMax = 0;
	iMax = max(iMax, iN * iA);
	iMax = max(iMax, iM * iB);
	iMax = max(iMax, iK * iC);

	vector<string> vecAns;
	if (iMax == iN * iA) vecAns.push_back("Joffrey");
	if (iMax == iM * iB) vecAns.push_back("Robb");
	if (iMax == iK * iC) vecAns.push_back("Stannis");

	int iSize = vecAns.size();
	for (int i = 0;i < iSize;++i)
	{
		cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
	}
	return 0;
}
