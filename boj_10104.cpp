#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int iN, iM;
	cin >> iN >> iM;
	list<int> listNumber;
	for (int i = 1; i <= iN; ++i)
	{
		listNumber.emplace_back(i);
	}
	while (iM--)
	{
		int iNumber;
		cin >> iNumber;
		int iSize = listNumber.size();
		auto iter = listNumber.begin();
		for (int i = 1; i <= iSize; ++i)
		{
			if (0 == i % iNumber)
			{
				iter = listNumber.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
	auto iter = listNumber.begin();
	while (iter != listNumber.end())
	{
		cout << *iter << "\n";
		++iter;
	}
	return 0;
}
