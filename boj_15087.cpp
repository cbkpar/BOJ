#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string Rotate(const string& strCode)
{
	const int iLength = strCode.length();
	string strAns;
	strAns.resize(iLength);

	int iSum = 0;
	for (int i = 0; i < iLength; ++i)
	{
		iSum += strCode[i] - 'A';
	}
	for (int i = 0; i < iLength; ++i)
	{
		int iTemp = strCode[i] - 'A';
		iTemp = (iTemp + iSum) % 26;
		strAns[i] = (char)(iTemp + 'A');
	}
	return strAns;
}

string Merge(const string& strFront, const string& strBack)
{
	const int iLength = strFront.length();
	string strAns;
	strAns.resize(iLength);

	for (int i = 0; i < iLength; ++i)
	{
		int iTemp = strFront[i] - 'A';
		iTemp = (iTemp + strBack[i] - 'A') % 26;
		strAns[i] = (char)(iTemp + 'A');
	}
	return strAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strCode;
	cin >> strCode;

	const int iLength = strCode.length();
	string strFront = Rotate(std::move(strCode.substr(0, iLength / 2)));
	string strBack = Rotate(std::move(strCode.substr(iLength / 2, iLength / 2)));

	cout << Merge(strFront, strBack) << "\n";
	return 0;
}
