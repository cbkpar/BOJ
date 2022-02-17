import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] presum = new long[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) presum[i] = presum[i - 1] + Long.parseLong(st.nextToken());
        long k = Long.parseLong(br.readLine());
        long ans = 0;
        int q = 1;
        for (int i = 1; i <= n; i++) {
            while (q <= n && presum[q] - presum[i - 1] <= k) q++;
            if (q == n + 1) break;
            ans += n - q + 1;
        }
        System.out.println(ans);
    }
}
