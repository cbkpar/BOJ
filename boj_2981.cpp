#include <iostream>
#include <list>
#include <algorithm>
#include <memory.h>

using namespace std;

int gcd(int a, int b)
{
	if (b % a == 0)
	{
		return a;
	}
	return gcd(b % a, a);
}

int main()
{
	int iN;
	cin >> iN;
	int* arrNumber = new int[iN];
	memset(arrNumber, 0, sizeof(int) * iN);
	int* arrDiff = new int[iN * (iN - 1) / 2];
	memset(arrDiff, 0, sizeof(int) * iN * (iN - 1) / 2);
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrNumber[i];
	}
	int iIndex = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = i + 1; j < iN; ++j)
		{
			int iDiff = arrNumber[i] - arrNumber[j];
			if (iDiff < 0)
			{
				iDiff = -iDiff;
			}
			arrDiff[iIndex++] = iDiff;
		}
	}
	int igcd = arrDiff[0];
	for (int i = 0; i < iN * (iN - 1) / 2; ++i)
	{
		if (igcd > arrDiff[i])
		{
			igcd = gcd(arrDiff[i], igcd);
		}
		else
		{
			igcd = gcd(igcd, arrDiff[i]);
		}
	}
	list<int> listAnswer;
	for (int i = 2; i * i <= igcd; ++i)
	{
		if (igcd % i == 0)
		{
			listAnswer.emplace_back(i);
			if (i * i != igcd)
			{
				listAnswer.emplace_back(igcd / i);
			}
		}
	}
	listAnswer.sort();
	for (int iNumber : listAnswer)
	{
		cout << iNumber << " ";
	}
	cout << igcd << "\n";
	delete[] arrNumber;
	delete[] arrDiff;
	return 0;
}
