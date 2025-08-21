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
	cin.ignore();

	for (int i = 0;i < iN;++i)
	{
		string strLine;
		getline(cin, strLine);

		vector<int> vecNum;

		int iNow = 0;
		for (char ch : strLine)
		{
			if (ch == ' ')
			{
				vecNum.push_back(iNow);
				iNow = 0;
			}
			else
			{
				iNow *= 10;
				iNow += ch - '0';
			}
		}
		vecNum.push_back(iNow);

		int iSize = vecNum.size();
		for (int i = 1;i < iSize;++i)
		{
			if (vecNum[i] >= 'a' && vecNum[i] <= 'z')
			{
				cout << (char)(vecNum[i]);
			}
			else if(vecNum[i] >= 'A' && vecNum[i] <= 'Z')
			{
				cout << (char)(vecNum[i] - 'A' + 'a');
			}
			else
			{
				cout << "-";
			}
		}
		if (vecNum[0] >= 'a' && vecNum[0] <= 'z')
		{
			cout << (char)(vecNum[0]);
		}
		else if (vecNum[0] >= 'A' && vecNum[0] <= 'Z')
		{
			cout << (char)(vecNum[0] - 'A' + 'a');
		}
		else
		{
			cout << "-";
		}
		cout << "ay" << "\n";
	}

	return 0;
}
