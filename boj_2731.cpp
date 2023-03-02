#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <string>

using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx>& a, bool inv = false) {
	int n = a.size(), j = 0;
	vector<cpx> roots(n / 2);
	for (int i = 1; i < n; i++) {
		int bit = (n >> 1);
		while (j >= bit) {
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int k = 1; k < n; k *= 2) {
		double angle = (inv ? PI / k : -PI / k);
		cpx dir(cos(angle), sin(angle));

		for (int i = 0; i < n; i += k * 2) {
			cpx unit(1, 0);

			for (int j = 0; j < k; j++) {
				cpx u = a[i + j];
				cpx v = a[i + j + k] * unit;

				a[i + j] = u + v;
				a[i + j + k] = u - v;

				unit *= dir;
			}
		}
	}
	if (inv) for (int i = 0; i < n; i++) a[i] /= n;
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b, int iK) {
	int n = 2;
	while (n < a.size() + b.size()) n *= 2;

	a.resize(n); FFT(a, 0);
	b.resize(n); FFT(b, 0);
	for (int i = 0; i < n; ++i) a[i] *= b[i];

	FFT(a, 1);
	vector<cpx> c(iK + 1);
	int iTemp = 0;
	for (int i = 0; i <= iK; ++i)
	{
		int iNum = (int)round(a[i].real());
		c[i] = cpx((iNum + iTemp) % 10, 0);
		iTemp = (iNum + iTemp) / 10;
	}
	return c;
}

int iSize;
int ArrAns[10] = { 0, };
int ArrNum[10] = { 0, };
bool bFound = false;

void DFS(int iK)
{
	if (bFound) return;
	if (iK == iSize)
	{
		long long lAns = 0;
		for (int i = iSize - 1; i >= 0; --i)
		{
			lAns *= 10;
			lAns += ArrAns[i];
		}
		cout << lAns << "\n";
		bFound = true;
		return;
	}
	for (int i = 0; i <= 9; ++i)
	{
		vector<cpx> vecA(iK + 1);
		vector<cpx> vecB(iK + 1);
		for (int i = 0; i < iK; ++i)
		{
			vecA[i] = vecB[i] = cpx(ArrAns[i], 0);
		}
		vecA[iK] = vecB[iK] = cpx(i, 0);
		vecA = multiply(vecA, vecB, iK);
		vecA = multiply(vecA, vecB, iK);
		if ((int)round(vecA[iK].real()) == ArrNum[iK])
		{
			ArrAns[iK] = i;
			DFS(iK + 1);
			if (bFound) return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strNum;
		cin >> strNum;
		iSize = strNum.length();
		for (int i = iSize - 1; i >= 0; --i) ArrNum[iSize - i - 1] = strNum[i] - '0';
		bFound = false;
		DFS(0);
	}
	return 0;
}
