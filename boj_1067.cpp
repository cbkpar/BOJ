#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

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
	double ang = 2 * PI / n * (inv ? -1 : 1);
	for (int i = 0; i < n / 2; i++) {
		roots[i] = cpx(cos(ang * i), sin(ang * i));
	}
	for (int i = 2; i <= n; i <<= 1) {
		int step = n / i;
		for (int j = 0; j < n; j += i) {
			for (int k = 0; k < i / 2; k++) {
				cpx u = a[j + k], v = a[j + k + i / 2] * roots[step * k];
				a[j + k] = u + v;
				a[j + k + i / 2] = u - v;
			}
		}
	}
	if (inv) for (int i = 0; i < n; i++) a[i] /= n;
}

vector<long long> multiply(vector<long long> v, vector<long long> w) {
	vector<cpx> a(v.begin(), v.end()), b(w.begin(), w.end());
	int n = 1;
	while (n < a.size() + 1 || n < b.size() + 1) n *= 2;
	n *= 2;
	a.resize(n);
	b.resize(n);

	FFT(a, 0);
	FFT(b, 0);
	for (int i = 0; i < n; ++i) a[i] *= b[i];

	FFT(a, 1);
	vector<long long> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = (long long)round(a[i].real());
	}
	return c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<long long> a(iN * 2), b(iN);
	for (int i = 0; i < iN; i++) { cin >> a[i]; a[i + iN] = a[i]; }
	for (int i = 1; i <= iN; i++) cin >> b[iN - i];
	vector<long long> ret = multiply(a, b);
	long long lAns = 0;
	for (long long a : ret) lAns = max(a, lAns);
	cout << lAns << "\n";

	return 0;
}
