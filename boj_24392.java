import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());

        final int MOD = 1000000007;

        //초기값 입력
        int[][] map = new int[iN][iM];
        for (int i = 0; i < iN; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < iM; ++j) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        //DP 계산
        for (int i = iN - 2; i >= 0; --i) {
            for (int j = 0; j < iM; ++j) {
                if (map[i][j] == 1) {
                    map[i][j] = map[i + 1][j];
                    if (j != 0) map[i][j] = (map[i][j] + map[i + 1][j - 1]) % MOD;
                    if (j != iM - 1) map[i][j] = (map[i][j] + map[i + 1][j + 1]) % MOD;
                }
            }
        }

        //정답 계산
        int iAnswer = 0;
        for (int i = 0; i < iM; ++i) {
            iAnswer = (iAnswer + map[0][i]) % MOD;
        }
        System.out.println(iAnswer);
    }
}
