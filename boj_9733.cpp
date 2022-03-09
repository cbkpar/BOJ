#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> map;
    map.insert(make_pair("Re", 0));
    map.insert(make_pair("Pt", 1));
    map.insert(make_pair("Cc", 2));
    map.insert(make_pair("Ea", 3));
    map.insert(make_pair("Tb", 4));
    map.insert(make_pair("Cm", 5));
    map.insert(make_pair("Ex", 6));

    int cnt[7] = {
        0,
    };
    int total;

    string behave;
    while (!(cin >> behave).eof()) {
        total++;
        if (!map.count(behave)) continue;
        cnt[map[behave]]++;
    }
    printf("Re %d %.2f\n", cnt[map["Re"]], ((float)cnt[map["Re"]] / total));
    printf("Pt %d %.2f\n", cnt[map["Pt"]], ((float)cnt[map["Pt"]] / total));
    printf("Cc %d %.2f\n", cnt[map["Cc"]], ((float)cnt[map["Cc"]] / total));
    printf("Ea %d %.2f\n", cnt[map["Ea"]], ((float)cnt[map["Ea"]] / total));
    printf("Tb %d %.2f\n", cnt[map["Tb"]], ((float)cnt[map["Tb"]] / total));
    printf("Cm %d %.2f\n", cnt[map["Cm"]], ((float)cnt[map["Cm"]] / total));
    printf("Ex %d %.2f\n", cnt[map["Ex"]], ((float)cnt[map["Ex"]] / total));
    printf("Total %d 1.00\n\n", total);
    return 0;
}
