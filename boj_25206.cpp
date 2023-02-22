#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strName, strGrade;
	float fGrade;

	float fSumScore = 0.f;
	float fSumGrade = 0.f;

	while (cin >> strName >> fGrade >> strGrade)
	{
		fSumGrade += fGrade;
		if (strGrade == "A+") fSumScore += fGrade * 4.5f;
		if (strGrade == "A0") fSumScore += fGrade * 4.0f;
		if (strGrade == "B+") fSumScore += fGrade * 3.5f;
		if (strGrade == "B0") fSumScore += fGrade * 3.0f;
		if (strGrade == "C+") fSumScore += fGrade * 2.5f;
		if (strGrade == "C0") fSumScore += fGrade * 2.0f;
		if (strGrade == "D+") fSumScore += fGrade * 1.5f;
		if (strGrade == "D0") fSumScore += fGrade * 1.0f;
		if (strGrade == "P") fSumGrade -= fGrade * 1.0f;
	}
	printf("%.06f", (fSumScore / fSumGrade));

	return 0;
}
