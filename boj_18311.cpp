#include <iostream>
#include <memory.h>

#define Safe_Delete_Array(p) {if(p) delete[] p;p=nullptr;}

typedef signed int _int;
typedef unsigned int _uint;
typedef signed long long _ll;

using namespace std;

int main()
{
	_int iN;
	_ll llK;
	cin >> iN >> llK;
	_int* arrDist = new _int[iN];
	memset(arrDist, 0, sizeof(_int) * iN);
	for (_uint i = 0; i < iN; ++i)
	{
		cin >> arrDist[i];
	}
	for (_uint i = 0; i < iN; ++i)
	{
		if (llK < arrDist[i])
		{
			cout << (i + 1) << endl;
			return 0;
		}
		llK -= arrDist[i];
	}
	for (_uint i = iN - 1; i >= 0; --i)
	{
		if (llK < arrDist[i])
		{
			cout << (i + 1) << endl;
			return 0;
		}
		llK -= arrDist[i];
	}
	Safe_Delete_Array(arrDist);
	return 0;
}
