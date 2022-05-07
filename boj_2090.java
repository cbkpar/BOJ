import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        long[] lArr = InputData();
        Solve(lArr);
    }

    private static long[] InputData() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        long[] lArr = new long[iN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; ++i) {
            lArr[i] = Long.parseLong(st.nextToken());
        }
        return lArr;
    }

    private static void Solve(long[] _lArr) {
        long lSumNumerator = 0;
        long lDenominator = 1;
        int iSize = _lArr.length;
        for (int i = 0; i < iSize; ++i) {
            lDenominator *= _lArr[i];
        }
        for (int i = 0; i < iSize; ++i) {
            long lTemp = 1;
            for (int j = 0; j < iSize; ++j) {
                if (i == j) continue;
                lTemp *= _lArr[j];
            }
            lSumNumerator += lTemp;
        }
        long lGCD = GCD(lSumNumerator, lDenominator);
        lSumNumerator /= lGCD;
        lDenominator /= lGCD;
        System.out.println(lDenominator + "/" + lSumNumerator);
    }

    private static long GCD(long _lA, long _lB) {
        if (_lA % _lB == 0) return _lB;
        return GCD(_lB, _lA % _lB);
    }
}
