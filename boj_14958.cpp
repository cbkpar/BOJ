#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <string.h>

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

vector<int> multiply(vector<cpx> a, vector<cpx> b) {
	int n = 2;
	while (n < a.size() + b.size()) n *= 2;

	a.resize(n); FFT(a, 0);
	b.resize(n); FFT(b, 0);
	for (int i = 0; i < n; ++i) a[i] *= b[i];

	FFT(a, 1);
	vector<int> c(n);
	for (int i = 0; i < n; ++i) c[i] = (int)round(a[i].real());
	return c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	string strA, strB;
	cin >> strA >> strB;

	vector<cpx> vecAR(iN);
	vector<cpx> vecAS(iN);
	vector<cpx> vecAP(iN);

	vector<cpx> vecBR(iK);
	vector<cpx> vecBS(iK);
	vector<cpx> vecBP(iK);

	for (int i = 0; i < iN; ++i)
	{
		switch (strA[i])
		{
		case 'R': vecAR[i] = 1; break;
		case 'S': vecAS[i] = 1; break;
		case 'P': vecAP[i] = 1; break;
		}
	}

	for (int i = 0; i < iK; ++i)
	{
		switch (strB[i])
		{
		case 'R': vecBR[iK - 1 - i] = 1; break;
		case 'S': vecBS[iK - 1 - i] = 1; break;
		case 'P': vecBP[iK - 1 - i] = 1; break;
		}
	}

	int iMax = 0;

	vector<int> vecR = multiply(vecAR, vecBP);
	vector<int> vecS = multiply(vecAS, vecBR);
	vector<int> vecP = multiply(vecAP, vecBS);

	int iSize = vecR.size();
	for (int i = iK - 1; i < iSize; ++i)
	{
		int iSum = vecR[i] + vecS[i] + vecP[i];
		if (iSum > iMax)
		{
			iMax = iSum;
		}
	}
	cout << iMax << "\n";
	return 0;
}
