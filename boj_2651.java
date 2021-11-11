import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int d = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 2];
        int[] time = new int[n + 2];
        long[] dp = new long[n + 2];
        Arrays.fill(dp, Long.MAX_VALUE);
        dp[0] = 0;
        int[] route = new int[n + 2];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n + 1; i++) arr[i] = arr[i - 1] + Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) time[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n + 1; j++) {
                if (arr[j] - arr[i] > d) break;
                if (dp[i] + time[i] < dp[j]) {
                    dp[j] = dp[i] + time[i];
                    route[j] = i;
                }
            }
        }
        int t = n + 1;
        Stack<Integer> s = new Stack<>();
        while (route[t] != 0) {
            s.add(route[t]);
            t = route[t];
        }
        sb.append(dp[n + 1] + "\n" + s.size() + "\n");
        if (s.size() > 0) {
            sb.append(s.pop());
            while (!s.isEmpty()) sb.append(" " + s.pop());
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
