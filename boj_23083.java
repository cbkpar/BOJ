import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, m, k, y, x, i, j;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(br.readLine());
        long[][] dp = new long[n + 2][m + 2];
        boolean[][] chk = new boolean[n + 2][m + 2];
        while (k-- > 0) {
            st = new StringTokenizer(br.readLine());
            y = Integer.parseInt(st.nextToken());
            x = Integer.parseInt(st.nextToken());
            chk[y][x] = true;
        }
        dp[0][0] = 1;
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (chk[j][i]) continue;
                if (i % 2 == 0) {
                    dp[j][i] = (dp[j][i - 1] + dp[j + 1][i - 1] + dp[j - 1][i]) % 1000000007L;
                } else {
                    dp[j][i] = (dp[j - 1][i] + dp[j - 1][i - 1] + dp[j][i - 1]) % 1000000007L;
                }
            }
        }
        System.out.println(dp[n][m]);
    }
}
