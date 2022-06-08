#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct tStudent
{
	int iNumber;
	int iCount;
};

bool bCheck[101] = { false, };
int main()
{
	int iN;
	cin >> iN;
	int iM;
	cin >> iM;
	list<tStudent> listStudent;
	for (int i = 0; i < iM; ++i)
	{
		int iNumber;
		cin >> iNumber;
		bool bCheck = true;
		for (auto& iter : listStudent)
		{
			if (iNumber == iter.iNumber)
			{
				bCheck = false;
				++iter.iCount;
				break;
			}
		}
		if (bCheck)
		{
			if (listStudent.size() < iN)
			{
				listStudent.push_back({ iNumber,1 });
			}
			else
			{
				int iMin = 99999;
				for (auto& iter : listStudent)
				{
					if (iMin > iter.iCount)
					{
						iMin = iter.iCount;
					}
				}
				for (auto iter = listStudent.cbegin(); iter != listStudent.cend(); )
				{
					if (iMin == iter->iCount)
					{
						iter = listStudent.erase(iter);
						break;
					}
					else
					{
						++iter;
					}
				}
				listStudent.push_back({ iNumber,1 });
			}
		}
	}
	for (auto& iter : listStudent)
	{
		bCheck[iter.iNumber] = true;
	}
	bool bFirst = true;
	for (int i = 1; i <= 100; ++i)
	{
		if (bCheck[i])
		{
			if (bFirst)
			{
				cout << i;
				bFirst = false;
			}
			else
			{
				cout << " " << i;
			}
		}
	}
	return 0;
}
