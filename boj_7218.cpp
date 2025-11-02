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

	int iLen;
	cin >> iLen;

	string strWord;
	cin >> strWord;

	vector<int> vecAns;

	if (strWord.find("I") != string::npos) vecAns.push_back(1);
	if (strWord.find("II") != string::npos) vecAns.push_back(2);
	if (strWord.find("III") != string::npos) vecAns.push_back(3);
	if (strWord.find("IV") != string::npos) vecAns.push_back(4);
	if (strWord.find("V") != string::npos) vecAns.push_back(5);
	if (strWord.find("VI") != string::npos) vecAns.push_back(6);
	if (strWord.find("VII") != string::npos) vecAns.push_back(7);
	if (strWord.find("VIII") != string::npos) vecAns.push_back(8);
	if (strWord.find("IX") != string::npos) vecAns.push_back(9);
	if (strWord.find("X") != string::npos) vecAns.push_back(10);
	if (strWord.find("XI") != string::npos) vecAns.push_back(11);
	if (strWord.find("XII") != string::npos) vecAns.push_back(12);

	int iSize = vecAns.size();
	for (int i = 0; i < iSize; ++i)
	{
		cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
	}
	return 0;
}
