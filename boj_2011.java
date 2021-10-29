import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int sz = str.length();
        int[] arr = new int[sz];
        for (int i = 0; i < sz; i++) arr[i] = str.charAt(i) - '0';
        int[][] dp = new int[sz + 1][2];
        if (arr[0] == 0) {
            System.out.println("0");
            return;
        }
        dp[0][0] = 1;
        for (int i = 1; i < sz; i++) {
            int t = arr[i - 1] * 10 + arr[i];
            if (arr[i] > 0) {
                dp[i][0] = (dp[i][0] + dp[i - 1][0]) % 1000000;
                dp[i][0] = (dp[i][0] + dp[i - 1][1]) % 1000000;
            }
            if (10 <= t && t <= 26) {
                dp[i][1] = (dp[i][1] + dp[i - 1][0]) % 1000000;
            }
        }
        System.out.println((dp[sz - 1][0] + dp[sz - 1][1]) % 1000000);
    }
}
