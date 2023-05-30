#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char Delimiter)
{
	istringstream iss(str);
	string buffer;
	vector<string> result;
	while (getline(iss, buffer, Delimiter))
	{
		result.push_back(buffer);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	cin.ignore();
	while (iN--)
	{
		string strWord;
		getline(cin, strWord);
		vector<string> result = split(strWord, ' ');
		for (string str : result)
		{
			int iSum = 0;
			for (char ch : str)
			{
				iSum += ch - 'a';
			}
			iSum %= 27;
			if (iSum == 26)
			{
				cout << " ";
			}
			else
			{
				cout << (char)(iSum + 'a');
			}
		}
		cout << "\n";
	}
	return 0;
}
