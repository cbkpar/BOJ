#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <string.h>

using namespace std;

bool bPrime[100001] = { false, };
vector<int> vecPrime;

int smallOddSwing[33] = { 1,1,1,3,3,15,5,35,35,315,63,693,231,3003,429,6435,6435,109395,
  12155,230945,46189,969969,88179,2028117,676039,16900975,1300075,
  35102025,5014575,145422675,9694845,300540195,300540195 };

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

vector<cpx> stringToComplexVectorBasedDecimal(string s)
{
	int length = s.size();

	vector<cpx> f(length);

	for (int i = 0; i < length; i++) {
		int num = s[i];
		f[i] = cpx(num, 0);
	}

	return f;
}

class BigInt {
	string digits;
public:

	BigInt(unsigned long long n = 0);
	BigInt(string&);
	BigInt(const char*);
	BigInt(BigInt&);
	BigInt(const BigInt& rhs);

	friend void divide_by_2(BigInt& a);
	friend bool Null(const BigInt&);
	friend int Length(const BigInt&);
	int operator[](const int)const;

	BigInt& operator=(const BigInt&);
	BigInt& operator++();
	BigInt operator++(int temp);
	BigInt& operator--();
	BigInt operator--(int temp);

	friend BigInt& operator+=(BigInt&, const BigInt&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	friend BigInt operator-(const BigInt&, const BigInt&);
	friend BigInt& operator-=(BigInt&, const BigInt&);

	friend bool operator==(const BigInt&, const BigInt&);
	friend bool operator!=(const BigInt&, const BigInt&);

	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator>=(const BigInt&, const BigInt&);
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);

	friend BigInt& operator*=(BigInt&, const BigInt&);
	friend BigInt operator*(const BigInt&, const BigInt&);
	friend BigInt& operator/=(BigInt&, const BigInt&);
	friend BigInt operator/(const BigInt&, const BigInt&);

	friend BigInt operator%(const BigInt&, const BigInt&);
	friend BigInt& operator%=(BigInt&, const BigInt&);

	friend BigInt& operator^=(BigInt&, const BigInt&);
	friend BigInt operator^(BigInt&, const BigInt&);

	friend BigInt sqrt(BigInt& a);

	friend ostream& operator<<(ostream&, const BigInt&);
	friend istream& operator>>(istream&, BigInt&);

};

BigInt::BigInt(string& s) {
	digits = "";
	int n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		if (!isdigit(s[i]))
			throw("ERROR");
		digits.push_back(s[i] - '0');
	}
}
BigInt::BigInt(unsigned long long nr) {
	do {
		digits.push_back(nr % 10);
		nr /= 10;
	} while (nr);
}
BigInt::BigInt(const char* s) {
	digits = "";
	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		if (!isdigit(s[i]))
			throw("ERROR");
		digits.push_back(s[i] - '0');
	}
}
BigInt::BigInt(BigInt& a) {
	digits = a.digits;
}

BigInt::BigInt(const BigInt& rhs) {
	digits = rhs.digits;
}

bool Null(const BigInt& a) {
	if (a.digits.size() == 1 && a.digits[0] == 0)
		return true;
	return false;
}
int Length(const BigInt& a) {
	return a.digits.size();
}
int BigInt::operator[](const int index)const {
	if (digits.size() <= index || index < 0)
		throw("ERROR");
	return digits[index];
}
bool operator==(const BigInt& a, const BigInt& b) {
	return a.digits == b.digits;
}
bool operator!=(const BigInt& a, const BigInt& b) {
	return !(a == b);
}
bool operator<(const BigInt& a, const BigInt& b) {
	int n = Length(a), m = Length(b);
	if (n != m)
		return n < m;
	while (n--)
		if (a.digits[n] != b.digits[n])
			return a.digits[n] < b.digits[n];
	return false;
}
bool operator>(const BigInt& a, const BigInt& b) {
	return b < a;
}
bool operator>=(const BigInt& a, const BigInt& b) {
	return !(a < b);
}
bool operator<=(const BigInt& a, const BigInt& b) {
	return !(a > b);
}

BigInt& BigInt::operator=(const BigInt& a) {
	digits = a.digits;
	return *this;
}

BigInt& BigInt::operator++() {
	int i, n = digits.size();
	for (i = 0; i < n && digits[i] == 9; i++)
		digits[i] = 0;
	if (i == n)
		digits.push_back(1);
	else
		digits[i]++;
	return *this;
}
BigInt BigInt::operator++(int temp) {
	BigInt aux;
	aux = *this;
	++(*this);
	return aux;
}

BigInt& BigInt::operator--() {
	if (digits[0] == 0 && digits.size() == 1)
		throw("UNDERFLOW");
	int i, n = digits.size();
	for (i = 0; digits[i] == 0 && i < n; i++)
		digits[i] = 9;
	digits[i]--;
	if (n > 1 && digits[n - 1] == 0)
		digits.pop_back();
	return *this;
}
BigInt BigInt::operator--(int temp) {
	BigInt aux;
	aux = *this;
	--(*this);
	return aux;
}

BigInt& operator+=(BigInt& a, const BigInt& b) {
	int t = 0, s, i;
	int n = Length(a), m = Length(b);
	if (m > n)
		a.digits.append(m - n, 0);
	n = Length(a);
	for (i = 0; i < n; i++) {
		if (i < m)
			s = (a.digits[i] + b.digits[i]) + t;
		else
			s = a.digits[i] + t;
		t = s / 10;
		a.digits[i] = (s % 10);
	}
	if (t)
		a.digits.push_back(t);
	return a;
}
BigInt operator+(const BigInt& a, const BigInt& b) {
	BigInt temp;
	temp = a;
	temp += b;
	return temp;
}

BigInt& operator-=(BigInt& a, const BigInt& b) {
	if (a < b)
		throw("UNDERFLOW");
	int n = Length(a), m = Length(b);
	int i, t = 0, s;
	for (i = 0; i < n; i++) {
		if (i < m)
			s = a.digits[i] - b.digits[i] + t;
		else
			s = a.digits[i] + t;
		if (s < 0)
			s += 10,
			t = -1;
		else
			t = 0;
		a.digits[i] = s;
	}
	while (n > 1 && a.digits[n - 1] == 0)
		a.digits.pop_back(),
		n--;
	return a;
}
BigInt operator-(const BigInt& a, const BigInt& b) {
	BigInt temp;
	temp = a;
	temp -= b;
	return temp;
}

BigInt& operator*=(BigInt& a, const BigInt& b)
{

	int n = a.digits.size();
	int m = b.digits.size();

	if (n <= 3 || m <= 3)
	{
		vector<int> v(n + m, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				v[i + j] += (a.digits[i]) * (b.digits[j]);
			}
		n += m;
		a.digits.resize(v.size());
		for (int s, i = 0, t = 0; i < n; i++)
		{
			s = t + v[i];
			v[i] = s % 10;
			t = s / 10;
			a.digits[i] = v[i];
		}
		for (int i = n - 1; i >= 1 && !v[i]; i--)
			a.digits.pop_back();
	}
	else
	{
		vector<cpx> A = stringToComplexVectorBasedDecimal(a.digits);
		vector<cpx> B = stringToComplexVectorBasedDecimal(b.digits);
		vector<long long> f = multiply(A, B);

		int dec = 10;
		for (int i = 0; i < f.size(); i++) {
			if (f[i] >= dec) {
				if (i == f.size() - 1)
					f.push_back((int)f[i] / dec);
				else
					f[i + 1] += (int)f[i] / dec;
				f[i] = (int)f[i] % dec;
			}
		}

		reverse(f.begin(), f.end());

		int zeroCheck = 0;
		for (int i = 0; i < f.size(); i++) {
			if (f[i] != 0) {
				zeroCheck = i;
				break;
			}
		}

		int iSize = f.size();
		a.digits.resize(iSize - zeroCheck);
		for (int i = zeroCheck; i < iSize; i++) {
			a.digits[iSize - i - 1] = (int)f[i];
		}
	}

	return a;
}
BigInt operator*(const BigInt& a, const BigInt& b) {
	BigInt temp;
	temp = a;
	temp *= b;
	return temp;
}

BigInt& operator/=(BigInt& a, const BigInt& b) {
	if (Null(b))
		throw("Arithmetic Error: Division By 0");
	if (a < b) {
		a = BigInt();
		return a;
	}
	if (a == b) {
		a = BigInt(1);
		return a;
	}
	int i, lgcat = 0, cc;
	int n = Length(a), m = Length(b);
	vector<int> cat(n, 0);
	BigInt t;
	for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
		t *= 10;
		t += a.digits[i];
	}
	for (; i >= 0; i--) {
		t = t * 10 + a.digits[i];
		for (cc = 9; cc * b > t; cc--);
		t -= cc * b;
		cat[lgcat++] = cc;
	}
	a.digits.resize(cat.size());
	for (i = 0; i < lgcat; i++)
		a.digits[i] = cat[lgcat - i - 1];
	a.digits.resize(lgcat);
	return a;
}
BigInt operator/(const BigInt& a, const BigInt& b) {
	BigInt temp;
	temp = a;
	temp /= b;
	return temp;
}

BigInt& operator%=(BigInt& a, const BigInt& b) {
	if (Null(b))
		throw("Arithmetic Error: Division By 0");
	if (a < b) {
		return a;
	}
	if (a == b) {
		a = BigInt();
		return a;
	}
	int i, lgcat = 0, cc;
	int n = Length(a), m = Length(b);
	vector<int> cat(n, 0);
	BigInt t;
	for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
		t *= 10;
		t += a.digits[i];
	}
	for (; i >= 0; i--) {
		t = t * 10 + a.digits[i];
		for (cc = 9; cc * b > t; cc--);
		t -= cc * b;
		cat[lgcat++] = cc;
	}
	a = t;
	return a;
}
BigInt operator%(const BigInt& a, const BigInt& b) {
	BigInt temp;
	temp = a;
	temp %= b;
	return temp;
}

BigInt& operator^=(BigInt& a, const BigInt& b) {
	BigInt Exponent, Base(a);
	Exponent = b;
	a = 1;
	while (!Null(Exponent)) {
		if (Exponent[0] & 1)
			a *= Base;
		Base *= Base;
		divide_by_2(Exponent);
	}
	return a;
}
BigInt operator^(BigInt& a, BigInt& b) {
	BigInt temp(a);
	temp ^= b;
	return temp;
}

void divide_by_2(BigInt& a) {
	int add = 0;
	for (int i = a.digits.size() - 1; i >= 0; i--) {
		int digit = (a.digits[i] >> 1) + add;
		add = ((a.digits[i] & 1) * 5);
		a.digits[i] = digit;
	}
	while (a.digits.size() > 1 && !a.digits.back())
		a.digits.pop_back();
}

BigInt sqrt(BigInt& a) {
	BigInt left(1), right(a), v(1), mid, prod;
	divide_by_2(right);
	while (left <= right) {
		mid += left;
		mid += right;
		divide_by_2(mid);
		prod = (mid * mid);
		if (prod <= a) {
			v = mid;
			++mid;
			left = mid;
		}
		else {
			--mid;
			right = mid;
		}
		mid = BigInt();
	}
	return v;
}

istream& operator>>(istream& in, BigInt& a) {
	string s;
	in >> s;
	int n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		if (!isdigit(s[i]))
			throw("INVALID NUMBER");
		a.digits[n - i - 1] = s[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const BigInt& a) {
	for (int i = a.digits.size() - 1; i >= 0; i--)
		cout << (short)a.digits[i];
	return
		cout;
}

BigInt product(const vector<BigInt>& multipliers, int i, int j) {
	if (i > j) return BigInt(1);
	if (i == j) return multipliers[i];
	int k = (i + j) >> 1;
	return product(multipliers, i, k) * product(multipliers, k + 1, j);
}

BigInt Swing(int iN)
{
	if (iN < 33) return smallOddSwing[iN];

	int count = 0;
	int rootN = (int)sqrt(iN);

	vector<BigInt> vecMultiple;

	auto iterA = lower_bound(vecPrime.begin(), vecPrime.end(), 3);
	while (iterA != vecPrime.end())
	{
		if (*iterA > iN) break;
		int q = iN;
		int p = 1;

		while (q /= *iterA)
		{
			if ((q & 1) == 1)
			{
				p *= *iterA;
			}
		}

		if (p > 1)
		{
			vecMultiple.emplace_back(BigInt(p));
		}
		++iterA;
	}

	return product(vecMultiple, 0, vecMultiple.size() - 1);
}

BigInt reFactorial(int iN)
{
	if (iN < 2) return BigInt(1);
	BigInt bigTemp = reFactorial(iN / 2);
	return (bigTemp * bigTemp) * Swing(iN);
}

BigInt Factorial(int iN)
{
	if (iN < 2) return BigInt(1);
	int iExp2 = iN;
	int iTemp = iN;
	while (iTemp)
	{
		iExp2 -= iTemp & 1;
		iTemp >>= 1;
	}

	BigInt bigNum = reFactorial(iN);

	BigInt bigTemp(2);
	bigTemp ^= iExp2;
	bigNum *= bigTemp;
	return bigNum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 100000; i++) if (!bPrime[i]) for (int j = i * i; j <= 100000; j += i) bPrime[j] = true;
	for (int i = 2; i <= 100000; i++) if (!bPrime[i]) vecPrime.push_back(i);

	int iN;
	cin >> iN;
	cout << Factorial(iN) << "\n";

	return 0;
}
