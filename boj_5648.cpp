#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

long long Reverse(long long lNumber)
{
	long long lTemp = 0;
	while (lNumber)
	{
		lTemp *= 10;
		lTemp += lNumber % 10;
		lNumber /= 10;
	}
	return lTemp;
}

int main()
{
	int iN;
	cin >> iN;
	list<long long> listNumber;
	while (iN--)
	{
		long long lNumber;
		cin >> lNumber;
		listNumber.push_back(Reverse(lNumber));
	}
	listNumber.sort();
	for (long long lNumber : listNumber)
	{
		cout << lNumber << "\n";
	}
	
	return 0;
}
