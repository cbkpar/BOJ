import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[][] Combination = new long[2001][2001];
        for (int i = 0; i <= 2000; ++i) {
            Combination[i][0] = 1;
            Combination[i][i] = 1;
        }
        for (int i = 1; i <= 2000; ++i) {
            for (int j = 1; j < i; ++j) {
                Combination[i][j] = (Combination[i - 1][j] + Combination[i - 1][j - 1]) % 1000000007;
            }
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iK = Integer.parseInt(st.nextToken());

        long lAns = Combination[iN][iK];
        long lTemp = 0;
        for (int i = 0; i < iK; ++i) {
            lTemp = (lTemp + Combination[iK - 1][i]) % 1000000007;
        }
        System.out.println(((lAns * lTemp) % 1000000007));
    }
}
