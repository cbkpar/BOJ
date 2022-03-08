#include <stdint.h>

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;
const int base = 1e9;
typedef vector<int> BigInt;

#define EL printf("\n")
#define pb push_back
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, r, l) for (int i = r; i >= l; i--)

void Set(BigInt &a) {
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}

void Print(BigInt a) {
    Set(a);
    printf("%d", (a.size() == 0) ? 0 : a.back());
    FORD(i, a.size() - 2, 0)
    printf("%09d", a[i]);
    EL;
}

BigInt Integer(string s) {
    BigInt ans;
    if (s[0] == '-') return ans;
    if (s.size() == 0) {
        ans.pb(0);
        return ans;
    }
    while (s.size() % 9 != 0) s = '0' + s;
    for (int i = 0; i < s.size(); i += 9) {
        int v = 0;
        for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
        ans.insert(ans.begin(), v);
    }
    Set(ans);
    return ans;
}

BigInt Integer(char c[]) {
    string s = "";
    FOR(i, 0, strlen(c) - 1)
    s = s + c[i];
    return Integer(s);
}

BigInt Integer(ll x) {
    string s = "";
    while (x > 0) s = char(x % 10 + '0') + s, x /= 10;
    return Integer(s);
}

BigInt Integer(int x) {
    return Integer((ll)x);
}

BigInt operator-(BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    FOR(i, 0, a.size() - 1) {
        carry += a[i] - (i < b.size() ? b[i] : 0);
        if (carry < 0)
            ans.pb(carry + base), carry = -1;
        else
            ans.pb(carry), carry = 0;
    }
    Set(ans);
    return ans;
}

BigInt operator*(BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    ans.assign(a.size() + b.size(), 0);
    FOR(i, 0, a.size() - 1) {
        ll carry = 0ll;
        for (int j = 0; j < b.size() || carry > 0; j++) {
            ll s = ans[i + j] + carry + (ll)a[i] * (j < b.size() ? (ll)b[j] : 0ll);
            ans[i + j] = s % base;
            carry = s / base;
        }
    }
    Set(ans);
    return ans;
}

bool operator<(BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (a.size() != b.size()) return (a.size() < b.size());
    FORD(i, a.size() - 1, 0)
    if (a[i] != b[i]) return (a[i] < b[i]);
    return false;
}

bool operator>(BigInt a, BigInt b) {
    return (b < a);
}

BigInt operator/(BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == Integer(0)) return Integer("-1");
    BigInt ans, cur;
    FORD(i, a.size() - 1, 0) {
        cur.insert(cur.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (b * Integer(mid) > cur) {
                x = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        cur = cur - Integer(x - 1) * b;
        ans.insert(ans.begin(), x - 1);
    }
    Set(ans);
    return ans;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    BigInt A = Integer(a);
    BigInt B = Integer(b);
    BigInt C = Integer(c);
    Print((B - C) / A);
    return 0;
}
