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

	int iN;
	cin >> iN;
	vector<cpx> vecNum(200001);
	vecNum[0] = cpx(1, 0);
	while (iN--)
	{
		int iNum;
		cin >> iNum;
		vecNum[iNum] = cpx(1, 0);
	}

	vector<int> vecAns = multiply(vecNum, vecNum);

	int iAns = 0;

	int iM;
	cin >> iM;
	while (iM--)
	{
		int iNum;
		cin >> iNum;
		if (vecAns[iNum])
		{
			++iAns;
		}
	}

	cout << iAns << "\n";

	return 0;
}
