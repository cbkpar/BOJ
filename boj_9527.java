import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static long[] dp;
    static long[] pow;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        dp = new long[56];
        pow = new long[56];
        dp[0] = pow[0] = 1;
        for (int i = 1; i <= 55; i++) {
            pow[i] = pow[i - 1] * 2;
            dp[i] = dp[i - 1] * 2 + pow[i];
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        long A = Long.parseLong(st.nextToken()) - 1;
        long B = Long.parseLong(st.nextToken());
        System.out.println(calc(B, 55) - calc(A, 55));
    }

    private static long calc(long n, int t) {
        if (n <= 1) return n;
        while (n < pow[t]) t--;
        return dp[t - 1] + n - pow[t] + 1 + calc(n - pow[t], t - 1);
    }
}
