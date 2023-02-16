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
	vector<int> c(1000001);
	for (int i = 5; i < 1000001; i+=2) c[i] = (int)round(a[i].real());
	return c;
}

bool bPrime[1000001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<cpx> vecPrime(1000001);
	vector<cpx> vecSemiPrime(1000001);


	for (int i = 2; i * i <= 1000000; ++i) if (!bPrime[i]) for (int j = i * i; j <= 1000000; j += i) bPrime[j] = true;
	for (int i = 3; i <= 1000000; i+=2)
	{
		if (!bPrime[i])
		{
			vecPrime[i] = cpx(1, 0);
		}
	}
	for (int i = 2; i <= 500000;++i)
	{
		if (!bPrime[i])
		{
			vecSemiPrime[i * 2] = cpx(1, 0);
		}
	}

	vector<int> vecAns = multiply(vecPrime, vecSemiPrime);
	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		cout << vecAns[iN] << "\n";
	}

	return 0;
}
