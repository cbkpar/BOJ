#include <iostream>
#include <memory.h>

#define Safe_Delete_Array(p) {if(p) delete[] p;p=nullptr;}

typedef signed int _int;
typedef unsigned int _uint;
typedef signed long long _ll;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	_uint iN, iQ;
	cin >> iN >> iQ;
	_int* arrScore = new int[iN];
	_int* arrAccScore = new int[iN];
	memset(arrScore, 0, sizeof(_int) * iN);
	memset(arrAccScore, 0, sizeof(_int) * iN);
	for (_uint i = 0; i < iN; ++i)
	{
		cin >> arrScore[i];
	}
	_ll lSum = 0;
	for (_uint i = 0; i < iN; ++i)
	{
		arrAccScore[i] = arrScore[i % iN] * arrScore[(i + 1) % iN] * arrScore[(i + 2) % iN] * arrScore[(i + 3) % iN];
		lSum += arrAccScore[i];
	}
	while (iQ--)
	{
		_int iNumber;
		cin >> iNumber;
		--iNumber;
		lSum -= (arrAccScore[iNumber] + arrAccScore[(iNumber - 1 + iN) % iN] + arrAccScore[(iNumber - 2 + iN) % iN] + arrAccScore[(iNumber - 3 + iN) % iN]) * 2;
		arrAccScore[iNumber] *= -1;
		arrAccScore[(iNumber - 1 + iN) % iN] *= -1;
		arrAccScore[(iNumber - 2 + iN) % iN] *= -1;
		arrAccScore[(iNumber - 3 + iN) % iN] *= -1;
		cout << lSum << "\n";
	}
	Safe_Delete_Array(arrScore);
	return 0;
}
