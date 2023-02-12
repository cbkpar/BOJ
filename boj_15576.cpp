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

	string strA, strB;
	cin >> strA >> strB;

	if (strA == "0" || strB == "0")
	{
		cout << "0\n";
		return 0;
	}

	int iSizeA = strA.length();
	int iSizeB = strB.length();
	vector<long long> vecA(iSizeA);
	vector<long long> vecB(iSizeB);

	for (int i = 1; i <= iSizeA; ++i) vecA[iSizeA - i] = (long long)strA[i - 1] - '0';
	for (int i = 1; i <= iSizeB; ++i) vecB[iSizeB - i] = (long long)strB[i - 1] - '0';

	vector<long long> vecAns = multiply(vecA, vecB);
	for (int i = 0; i < vecAns.size(); ++i)
	{
		if (vecAns[i] > 9 && i == vecAns.size() - 1) vecAns.push_back(0);
		if (vecAns[i] > 9) vecAns[i + 1] += vecAns[i] / 10, vecAns[i] %= 10;
	}

	int iSizeAns = vecAns.size();
	for (int i = iSizeAns - 1; i >= 0; --i)
	{
		if (vecAns[i] != 0)
		{
			for (int j = i; j >= 0; --j)
			{
				cout << (char)(vecAns[j] + '0');
			}
			break;
		}
	}
	cout << "\n";

	return 0;
}
