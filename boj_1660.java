import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dp = new int[121];
        for (int i = 1; i <= 120; i++) dp[i] = (i * (i + 1) * (i + 2)) / 6;
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        Arrays.fill(arr, 999999);
        arr[0] = 0;
        int cnt = 0;
        for (int i = 1; i <= 120; i++) {
            for (int j = dp[i]; j <= n; j++) {
                arr[j] = Math.min(arr[j], arr[j - dp[i]] + 1);
            }
        }
        System.out.println(arr[n]);
    }
}
