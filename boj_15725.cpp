#include <string.h>
#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int sz = str.size();
    for (int i = 0; i < sz; i++) {
        if (str[i] == 'x') {
            int ans = 0;
            bool negative = false;
            int idx = 0;
            if (str[0] == 'x') {
                cout << "1" << endl;
                return 0;
            } else if (str[0] == '-') {
                negative = true;
                if (i == 1) ans = 1;
                idx++;
            }
            while (idx < i) {
                ans *= 10;
                ans += str[idx++] - '0';
            }
            cout << (negative ? "-" : "") << ans << endl;
            return 0;
        }
    }
    cout << "0" << endl;
    return 0;
}
