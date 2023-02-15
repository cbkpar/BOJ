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

vector<long long> multiply(vector<cpx> a, vector<cpx> b) {
	int n = 2;
	while (n < a.size() + b.size()) n *= 2;

	a.resize(n); FFT(a, 0);
	b.resize(n); FFT(b, 0);
	for (int i = 0; i < n; ++i) a[i] *= b[i];

	FFT(a, 1);
	vector<long long> c(n);
	for (int i = 0; i < n; ++i) c[i] = (long long)round(a[i].real());
	return c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<long long> arrPowCount(iN);
	for (int i = 1; i < iN; ++i)
	{
		long long lNum = (long long)i * i;
		++arrPowCount[lNum % iN];
	}

	vector<cpx> a(iN);
	for (int i = 0; i < iN; ++i) a[i] = cpx(arrPowCount[i], 0);
	vector<long long> ret = multiply(a, a);
	vector<long long> arrCount(iN);
	int iSize = ret.size();
	for (int i = 0; i < iSize; ++i)
	{
		arrCount[i % iN] += ret[i];
	}
	for (int i = 0; i < iN; ++i)
	{
		arrCount[(i * 2) % iN] += arrPowCount[i];
	}
	for (int i = 0; i < iN; ++i)
	{
		arrCount[i] /= 2;
	}
	long long lAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		lAns += arrCount[i] * arrPowCount[i];
	}
	cout << lAns << "\n";
	return 0;
}
