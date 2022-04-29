import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static String Str;
    static int iLen, iMax;
    static boolean[] bCheck;
    static int[] aNumber;
    static int[] aAnswer;
    static boolean bFind;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        Str = br.readLine();
        iLen = Str.length();
        iMax = iLen >= 10 ? (iLen - 9) / 2 + 9 : iLen;
        bCheck = new boolean[iMax + 1];
        aNumber = new int[iMax];
        aAnswer = new int[iMax];
        bFind = false;
        Backtracking(0, 0);
        for (int i = 0; i < iMax; ++i) {
            sb.append(aAnswer[i] + " ");
        }
        System.out.println(sb.toString().trim());
    }

    private static void Backtracking(int i, int k) {
        if (bFind) return;
        if (k == iMax) {
            bFind = true;
            for (int j = 0; j < iMax; ++j) {
                aAnswer[j] = aNumber[j];
            }
            return;
        }
        if (i < iLen && Str.charAt(i) == '0') return;
        if (i < iLen) {
            int tmp = Str.charAt(i) - '0';
            if (tmp <= iMax && !bCheck[tmp]) {
                bCheck[tmp] = true;
                aNumber[k] = tmp;
                Backtracking(i + 1, k + 1);
                bCheck[tmp] = false;
            }
        }
        if (i < iLen - 1) {
            int tmp = (Str.charAt(i) - '0') * 10 + (Str.charAt(i + 1) - '0');
            if (tmp <= iMax && !bCheck[tmp]) {
                bCheck[tmp] = true;
                aNumber[k] = tmp;
                Backtracking(i + 2, k + 1);
                bCheck[tmp] = false;
            }
        }
    }
}
