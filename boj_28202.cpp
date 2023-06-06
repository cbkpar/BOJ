#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool IsRepdigit(const string& str)
{
	int iLen = str.length();
	if (str[0] < '0') return false;
	for (int i = 0; i < iLen; ++i)
	{
		if (str[i] != '0') break;
		if (i == iLen - 1) return false;
	}
	for (int i = 0; i < iLen - 1; ++i)
	{
		if (str[i] == '0') continue;
		if (str[i] != str[i + 1]) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strNum;
		cin >> strNum;

		int iLen = strNum.length();
		string strTemp = strNum;
		for (int i = 0; i < iLen; ++i)
		{
			if (strTemp[i] < '1')
			{
				--strTemp[i - 1];
				strTemp[i] += 9;
			}
			else
			{
				--strTemp[i];
			}
		}
		if (IsRepdigit(strTemp))
		{
			for (int i = 0; i < iLen; ++i)
			{
				cout << '1';
			}
			cout << " ";
			for (int i = 0; i < iLen; ++i)
			{
				if (strTemp[i] > '0')
				{
					for (int j = i; j < iLen; ++j)
					{
						cout << strTemp[j];
					}
					break;
				}
			}
			cout << "\n";
		}
		else
		{
			bool bFound = false;
			for (int k = 1; k <= 9; ++k)
			{
				string strTemp = strNum;
				for (int i = iLen - 1; i >= 1; --i)
				{
					if (strTemp[i] < k + '0')
					{
						--strTemp[i - 1];
						strTemp[i] += 10 - k;
					}
					else
					{
						strTemp[i] -= k;
					}
				}
				if (IsRepdigit(strTemp))
				{
					for (int i = 1; i < iLen; ++i)
					{
						cout << k;
					}
					cout << " ";
					for (int i = 0; i < iLen; ++i)
					{
						if (strTemp[i] > '0')
						{
							for (int j = i; j < iLen; ++j)
							{
								cout << strTemp[j];
							}
							break;
						}
					}
					cout << "\n";
					bFound = true;
					break;
				}
			}
			if (!bFound)
			{
				for (int k = 1; k <= strNum[0] - '0'; ++k)
				{
					string strTemp = strNum;
					for (int i = iLen - 1; i >= 0; --i)
					{
						if (strTemp[i] < k + '0')
						{
							--strTemp[i - 1];
							strTemp[i] += 10 - k;
						}
						else
						{
							strTemp[i] -= k;
						}
					}
					if (IsRepdigit(strTemp))
					{
						for (int i = 0; i < iLen; ++i)
						{
							cout << k;
						}
						cout << " ";
						for (int i = 0; i < iLen; ++i)
						{
							if (strTemp[i] > '0')
							{
								for (int j = i; j < iLen; ++j)
								{
									cout << strTemp[j];
								}
								break;
							}
						}
						cout << "\n";
						break;
					}
				}
			}
		}
	}
	return 0;
}
