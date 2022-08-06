#include <iostream>
#include <memory.h>
#include <algorithm>

#define Safe_Release_Array(p) if(p){delete[] p;p=nullptr;}

using namespace std;

struct tagStudent
{
	int iScoreA;
	int iScoreB;
};

int main()
{
	int iN, iM, iK;
	cin >> iN >> iM >> iK;
	tagStudent* pStudent = new tagStudent[iN];
	memset(pStudent, 0, sizeof(tagStudent) * iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> pStudent[i].iScoreA >> pStudent[i].iScoreB;
	}
	sort(pStudent, pStudent + iN, [](const tagStudent& o1, const tagStudent& o2)
		{
			return o1.iScoreB > o2.iScoreB;
		});
	sort(pStudent + iK, pStudent + iN, [](const tagStudent& o1, const tagStudent& o2)
		{
			return o1.iScoreA > o2.iScoreA;
		});
	long long lSumScore = 0;
	for (int i = 0; i < iM + iK; ++i)
	{
		lSumScore += pStudent[i].iScoreA;
	}
	cout << lSumScore << endl;
	Safe_Release_Array(pStudent);
	return 0;
}
