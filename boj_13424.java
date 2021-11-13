import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[][] dist = new int[n + 1][n + 1];
            for (int i = 1; i <= n; i++) Arrays.fill(dist[i], 1000000000);
            for (int i = 1; i <= n; i++) dist[i][i] = 0;
            while (m-- > 0) {
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                dist[s][e] = Math.min(dist[s][e], w);
                dist[e][s] = Math.min(dist[e][s], w);
            }
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
            int sz = Integer.parseInt(br.readLine());
            int[] arr = new int[sz];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < sz; i++) arr[i] = Integer.parseInt(st.nextToken());
            int ans = 1;
            long mx = Long.MAX_VALUE;
            for (int i = 1; i <= n; i++) {
                long sum = 0;
                for (int j = 0; j < sz; j++) sum += dist[i][arr[j]];
                if (sum < mx) {
                    mx = sum;
                    ans = i;
                }
            }
            sb.append(ans + "\n");
        }
        System.out.println(sb);
    }
}
