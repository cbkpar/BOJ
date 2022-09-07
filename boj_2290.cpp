#include <iostream>
#include <string>

using namespace std;

bool top[10] = { true, false, true, true, false, true, true, true, true, true };
bool middle[10] = { false, false, true, true, true, true, true, false, true, true };
bool bottom[10] = { true, false, true, true, false, true, true, false, true, true };
bool lefttop[10] = { true, false, false, false, true, true, true, false, true, true };
bool leftbottom[10] = { true, false, true, false, false, false, true, false, true, false };
bool righttop[10] = { true, true, true, true, true, false, false, true, true, true };
bool rightbottom[10] = { true, true, false, true, true, true, true, true, true, true };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iS;
	cin >> iS;
	string strNumber;
	cin >> strNumber;
	int iLen;
	iLen = strNumber.length();
	
	for (int i = 0; i < iLen; ++i)
	{
		cout << " ";
		if (top[strNumber[i] - '0'])
		{
			for (int j = 0; j < iS; ++j)
			{
				cout << "-";
			}
		}
		else
		{
			for (int j = 0; j < iS; ++j)
			{
				cout << " ";
			}
		}
		cout << " ";
		if (i + 1 != iLen)
		{
			cout << " ";
		}
	}
	cout << "\n";
	for (int i = 0; i < iS; ++i)
	{
		for (int j = 0; j < iLen; ++j)
		{
			if (lefttop[strNumber[j] - '0'])
			{
				cout << "|";
			}
			else
			{
				cout << " ";
			}
			for (int k = 0; k < iS; ++k)
			{
				cout << " ";
			}
			if (righttop[strNumber[j] - '0'])
			{
				cout << "|";
			}
			else
			{
				cout << " ";
			}
			if (j + 1 != iLen)
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	for (int i = 0; i < iLen; ++i)
	{
		cout << " ";
		if (middle[strNumber[i] - '0'])
		{
			for (int j = 0; j < iS; ++j)
			{
				cout << "-";
			}
		}
		else
		{
			for (int j = 0; j < iS; ++j)
			{
				cout << " ";
			}
		}
		cout << " ";
		if (i + 1 != iLen)
		{
			cout << " ";
		}
	}
	cout << "\n";
	for (int i = 0; i < iS; ++i)
	{
		for (int j = 0; j < iLen; ++j)
		{
			if (leftbottom[strNumber[j] - '0'])
			{
				cout << "|";
			}
			else
			{
				cout << " ";
			}
			for (int k = 0; k < iS; ++k)
			{
				cout << " ";
			}
			if (rightbottom[strNumber[j] - '0'])
			{
				cout << "|";
			}
			else
			{
				cout << " ";
			}
			if (j + 1 != iLen)
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	for (int i = 0; i < iLen; ++i)
	{
		cout << " ";
		if (bottom[strNumber[i] - '0'])
		{
			for (int j = 0; j < iS; ++j)
			{
				cout << "-";
			}
		}
		else
		{
			for (int j = 0; j < iS; ++j)
			{
				cout << " ";
			}
		}
		cout << " ";
		if (i + 1 != iLen)
		{
			cout << " ";
		}
	}
	cout << "\n";
}
