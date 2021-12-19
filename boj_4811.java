import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        long[][] dp = new long[31][31];
        for (int i = 0; i <= 30; i++) dp[0][i] = 1;
        for (int i = 1; i <= 30; i++) {
            for (int j = i; j <= 30; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            sb.append(dp[n][n] + "\n");
        }
        System.out.println(sb);
    }
}
