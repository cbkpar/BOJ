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
        dp[0] = 1;
        dp[1] = 4;
        long tmp = 4;
        for (int i = 2; i <= 55; i++) {
            dp[i] = dp[i - 1] * 2 + tmp;
            tmp *= 2;
        }
        pow = new long[56];
        pow[0] = 1;
        for (int i = 1; i <= 55; i++) pow[i] = pow[i - 1] * 2;
        StringTokenizer st = new StringTokenizer(br.readLine());
        long A = Long.parseLong(st.nextToken());
        long B = Long.parseLong(st.nextToken());
        System.out.println(calc(B) - calc(A - 1));
    }

    private static long calc(long n) {
        if (n <= 1) return n;
        long cnt = 0;
        int t = 0;
        while (true) {
            if (n < pow[t]) break;
            t++;
        }
        t--;
        cnt += dp[t - 1] + n - pow[t] + 1;
        cnt += calc(n - pow[t]);
        return cnt;
    }
}
