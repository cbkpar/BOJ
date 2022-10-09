#include <iostream>

using namespace std;

int CalcDay(int iDay, int iMonth, int iYear)
{
	return iDay + iMonth * 30 + iYear * 360;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iFirstDay, iFirstMonth, iFirstYear, iDate;
	int iSecondDay, iSecondMonth, iSecondYear;
	cin >> iFirstDay >> iFirstMonth >> iFirstYear >> iDate;
	cin >> iSecondDay >> iSecondMonth >> iSecondYear;
	int iDiff = CalcDay(iSecondDay, iSecondMonth, iSecondYear) - CalcDay(iFirstDay, iFirstMonth, iFirstYear);
	iDate += iDiff;
	cout << (iDate + 6) % 7 + 1 << "\n";
	return 0;
}
