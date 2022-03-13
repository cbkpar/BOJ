import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] storage = new int[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) storage[i][j] = str.charAt(j) - '0';
        }
        int[][] dp = new int[n][m];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j][i] = dp[j][i - 1] + storage[j][i - 1];
                if (j != 0) dp[j][i] = Math.max(dp[j][i], dp[j - 1][i - 1] + storage[j - 1][i - 1]);
                if (j != n - 1) dp[j][i] = Math.max(dp[j][i], dp[j + 1][i - 1] + storage[j + 1][i - 1]);
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++) mx = Math.max(mx, dp[i][m - 1]);
        System.out.println(mx);
    }
}
