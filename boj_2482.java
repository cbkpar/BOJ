import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        int iK = Integer.parseInt(br.readLine());
        System.out.println(Solve(iN, iK));
    }

    private static int Solve(int N, int K) {
        int[][] dp = new int[N + 1][K + 1];
        for (int i = 0; i <= N; ++i) dp[i][0] = 1;
        for (int i = 0; i <= N; ++i) dp[i][1] = i;
        for (int i = 2; i <= N; ++i) {
            for (int j = 2; j <= K; ++j) {
                dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
                if (j >= i) break;
            }
        }
        return (dp[N - 3][K - 1] + dp[N - 1][K]) % 1000000003;
    }
}
