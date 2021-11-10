import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int[] arr;
    static int[][] dp;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        dp = new int[n][n];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        System.out.println(divide(0, n - 1));
    }

    private static int divide(int s, int e) {
        if (s > e) return 0;
        if (dp[s][e] != -1) return dp[s][e];
        if (arr[s] == arr[e]) {
            return dp[s][e] = divide(s + 1, e - 1);
        } else {
            return dp[s][e] = 1 + Math.min(divide(s + 1, e), divide(s, e - 1));
        }
    }
}
