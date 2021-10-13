import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 9999);
        dp[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= arr[i]; j++) {
                if (i + j > n) break;
                dp[i + j] = Math.min(dp[i + j], dp[i] + 1);
            }
        }
        System.out.println(dp[n]==9999?"-1":dp[n]);
    }
}
