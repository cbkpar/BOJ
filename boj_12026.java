import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String args[]) throws IOException {
        int n, i, j;
        String str;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        str = br.readLine();
        int[][] dp = new int[n][3];
        for (i = 0; i < n; i++) Arrays.fill(dp[i], 1000000000);
        dp[0][0] = 0;
        for (i = 1; i < n; i++) {
            if (str.charAt(i) == 'B') {
                for (j = 0; j < i; j++) {
                    if (str.charAt(j) == 'J') {
                        dp[i][0] = Math.min(dp[i][0], dp[j][2] + (int) Math.pow(j - i, 2));
                    }
                }
            } else if (str.charAt(i) == 'O') {
                for (j = 0; j < i; j++) {
                    if (str.charAt(j) == 'B') {
                        dp[i][1] = Math.min(dp[i][1], dp[j][0] + (int) Math.pow(j - i, 2));
                    }
                }
            } else {
                for (j = 0; j < i; j++) {
                    if (str.charAt(j) == 'O') {
                        dp[i][2] = Math.min(dp[i][2], dp[j][1] + (int) Math.pow(j - i, 2));
                    }
                }
            }
        }
        if (str.charAt(n - 1) == 'B') {
            System.out.println(dp[n - 1][0] == 1000000000 ? "-1" : dp[n - 1][0]);
        } else if (str.charAt(n - 1) == 'O') {
            System.out.println(dp[n - 1][1] == 1000000000 ? "-1" : dp[n - 1][1]);
        } else {
            System.out.println(dp[n - 1][2] == 1000000000 ? "-1" : dp[n - 1][2]);
        }
    }
}
