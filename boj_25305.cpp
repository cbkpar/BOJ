#include <iostream>
#include <algorithm>
#include <memory.h>

#define Safe_Delete_Array(p) {if(p) delete[] p;p=nullptr;}

using namespace std;

int main()
{
	int iN, iK;
	cin >> iN >> iK;
	int* arrScore = new int[iN];
	memset(arrScore, 0, sizeof(int) * iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrScore[i];
	}
	sort(arrScore, arrScore + iN, greater<>());
	cout << arrScore[iK-1] << endl;
	Safe_Delete_Array(arrScore);
	return 0;
}
