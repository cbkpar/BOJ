#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long gcd(long long iA, long long iB)
{
	if (iA > iB) swap(iA, iB);
	if (iB % iA == 0) return iA;
	return gcd(iB % iA, iA);
}

vector<long long> Plus(const vector<long long>& vecA, const vector<long long>& vecB)
{
	vector<long long> vecAns(4);
	vecAns[0] = vecA[0] * vecB[0];
	vecAns[1] = vecA[0] * vecB[1] + vecA[1] * vecB[0];
	vecAns[2] = vecA[0] * vecB[2] + vecA[2] * vecB[0];
	vecAns[3] = (vecAns[2] == 0 ? 0 : vecA[3]);
	if (vecAns[3] == 0) vecAns[2] = 0;

	long long lGCD = abs(vecAns[0]);
	if (vecAns[1] != 0) lGCD = gcd(lGCD, abs(vecAns[1]));
	if (vecAns[2] != 0) lGCD = gcd(lGCD, abs(vecAns[2]));

	for (long long i = 0; i < 3; ++i) vecAns[i] /= lGCD;
	return vecAns;
}

vector<long long> Minus(const vector<long long>& vecA, const vector<long long>& vecB)
{
	vector<long long> vecAns(4);
	vecAns[0] = vecA[0] * vecB[0];
	vecAns[1] = vecA[1] * vecB[0] - vecA[0] * vecB[1];
	vecAns[2] = vecA[2] * vecB[0] - vecA[0] * vecB[2];
	vecAns[3] = (vecAns[2] == 0 ? 0 : vecA[3]);
	if (vecAns[3] == 0) vecAns[2] = 0;

	long long lGCD = abs(vecAns[0]);
	if (vecAns[1] != 0) lGCD = gcd(lGCD, abs(vecAns[1]));
	if (vecAns[2] != 0) lGCD = gcd(lGCD, abs(vecAns[2]));

	for (long long i = 0; i < 3; ++i) vecAns[i] /= lGCD;
	return vecAns;
}

vector<long long> Multiply(const vector<long long>& vecA, const vector<long long>& vecB)
{
	vector<long long> vecAns(4);
	vecAns[0] = vecA[0] * vecB[0];
	vecAns[1] = vecA[1] * vecB[1] + vecA[2] * vecB[2] * vecA[3];
	vecAns[2] = vecA[1] * vecB[2] + vecA[2] * vecB[1];
	vecAns[3] = (vecAns[2] == 0 ? 0 : vecA[3]);
	if (vecAns[3] == 0) vecAns[2] = 0;

	long long lGCD = abs(vecAns[0]);
	if (vecAns[1] != 0) lGCD = gcd(lGCD, abs(vecAns[1]));
	if (vecAns[2] != 0) lGCD = gcd(lGCD, abs(vecAns[2]));

	for (long long i = 0; i < 3; ++i) vecAns[i] /= lGCD;
	return vecAns;
}

vector<long long> Divide(const vector<long long>& vecA, const vector<long long>& vecB)
{
	vector<long long> vecAns(4);
	vecAns[0] = vecA[0] * (vecB[1] * vecB[1] - vecB[2] * vecB[2] * vecB[3]);
	vecAns[1] = vecB[0] * (vecA[1] * vecB[1] - vecA[2] * vecB[2] * vecA[3]);
	vecAns[2] = vecB[0] * (vecB[1] * vecA[2] - vecA[1] * vecB[2]);
	vecAns[3] = (vecAns[2] == 0 ? 0 : vecA[3]);
	if (vecAns[3] == 0) vecAns[2] = 0;

	long long lGCD = abs(vecAns[0]);
	if (vecAns[1] != 0) lGCD = gcd(lGCD, abs(vecAns[1]));
	if (vecAns[2] != 0) lGCD = gcd(lGCD, abs(vecAns[2]));

	if (vecAns[0] < 0) lGCD *= -1;
	for (long long i = 0; i < 3; ++i) vecAns[i] /= lGCD;
	return vecAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> vecA(4);
	vector<long long> vecB(4);

	for (long long i = 0; i < 4; ++i) cin >> vecA[i];
	for (long long i = 0; i < 4; ++i) cin >> vecB[i];

	vector<long long> vecPlus = Plus(vecA, vecB);
	cout << vecPlus[0] << " " << vecPlus[1] << " " << vecPlus[2] << " " << vecPlus[3] << "\n";

	vector<long long> vecMinus = Minus(vecA, vecB);
	cout << vecMinus[0] << " " << vecMinus[1] << " " << vecMinus[2] << " " << vecMinus[3] << "\n";

	vector<long long> vecMultiply = Multiply(vecA, vecB);
	cout << vecMultiply[0] << " " << vecMultiply[1] << " " << vecMultiply[2] << " " << vecMultiply[3] << "\n";

	vector<long long> vecDivide = Divide(vecA, vecB);
	cout << vecDivide[0] << " " << vecDivide[1] << " " << vecDivide[2] << " " << vecDivide[3] << "\n";

	return 0;
}
