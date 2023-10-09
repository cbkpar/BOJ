#include <iostream>
#include <vector>
#include <algorithm>

#define 입력 cin
#define 출력 cout
#define 줄내림 "\n"
#define 한글날 20231009

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	입력.tie(NULL);
	출력.tie(NULL);

	int 팀;
	입력 >> 팀;

	int 금액 = 팀 * (한글날 - 20227009);
	출력 << 금액 << 줄내림;
	return 0;
}
