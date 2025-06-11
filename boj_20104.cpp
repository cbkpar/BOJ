#include "timecard.h"

static int N;

void init(int n) {
	N = n;
}

std::string convert(std::string s) {
    int iLen =s.length();
    for(int i=0;i<iLen;++i)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] -'A'+'a';
        }
    }
	return s;
}
