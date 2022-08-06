#include <iostream>
#include <algorithm>

#define Safe_Release_Array(p) if(p){delete[] p;p=nullptr;}

using namespace std;

struct town
{
	int iCost;
	int iPeople;
};

int g_iMaxPeople = 0;

void CalcMaxPeople(town* _pTown, const int& _iN, int _iK, int _iNowCost, int _iAccCost, const int& _iMaxCost, int _iMaxPeople)
{
	if (_iK == _iN)
	{
		if (_iMaxPeople > g_iMaxPeople)
		{
			g_iMaxPeople = _iMaxPeople;
		}
		return;
	}
	if (_iNowCost + _iAccCost + _pTown[_iK].iCost <= _iMaxCost)
	{
		CalcMaxPeople(_pTown, _iN, _iK + 1, _iNowCost + _iAccCost + _pTown[_iK].iCost, _iAccCost + _pTown[_iK].iCost, _iMaxCost, _iMaxPeople + _pTown[_iK].iPeople);
	}
	CalcMaxPeople(_pTown, _iN, _iK + 1, _iNowCost, _iAccCost, _iMaxCost, _iMaxPeople);
}

int main()
{
	int iN, iMaxCost;
	cin >> iN >> iMaxCost;
	town* pTown = new town[iN];
	for (int i = 0; i < iN; ++i)
	{
		cin >> pTown[i].iCost;
	}
	for (int i = 0; i < iN; ++i)
	{
		cin >> pTown[i].iPeople;
	}
	sort(pTown, pTown + iN, [](const town& o1, const town& o2)
		{
			if (o1.iCost == o2.iCost)
			{
				return o2.iPeople < o1.iPeople;
			}
			return o1.iCost < o2.iCost;
		});
	CalcMaxPeople(pTown, iN, 0, 0, 0, iMaxCost, 0);
	cout << g_iMaxPeople << endl;
	Safe_Release_Array(pTown);
	return 0;
}
