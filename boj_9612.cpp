#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	vector<string> vecWord;
	for (int i = 0; i < iN; ++i)
	{
		string str;
		cin >> str;
		vecWord.push_back(str);
	}
	sort(vecWord.begin(), vecWord.end());
	int iMaxCount = 1;
	int iNowCount = 1;
	int iAnswerIndex = 0;
	for (int i = 1; i < iN; ++i)
	{
		if (vecWord[i - 1] == vecWord[i])
		{
			++iNowCount;
		}
		else
		{
			iNowCount = 1;
		}
		if (iNowCount >= iMaxCount)
		{
			iMaxCount = iNowCount;
			iAnswerIndex = i;
		}
	}
	cout << vecWord[iAnswerIndex] << " " << iMaxCount << endl;
	return 0;
}
