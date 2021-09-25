import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int sz, i, a, b;
        String str = br.readLine();
        sz = str.length();
        int[][] dp = new int[sz][2];
        if (str.charAt(0) - '0' != 0) dp[0][0] = 1;
        if (sz >= 2) {
            a = str.charAt(1) - '0';
            if (a != 0) dp[1][0] = 1;
            b = (str.charAt(0) - '0') * 10 + (str.charAt(1) - '0');
            if (b <= 34 && b >= 10) dp[1][1] = 1;
        }
        for (i = 2; i < sz; i++) {
            a = str.charAt(i) - '0';
            b = (str.charAt(i - 1) - '0') * 10 + (str.charAt(i) - '0');
            if (a != 0) dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            if (b <= 34 && b >= 10) dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
        }
        System.out.println(dp[sz - 1][0] + dp[sz - 1][1]);
    }
}
