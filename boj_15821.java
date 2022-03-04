import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        long[] dist = new long[n];
        for (int i = 0; i < n; i++) {
            int p = Integer.parseInt(br.readLine());
            long mx = 0;
            st = new StringTokenizer(br.readLine());
            while (p-- > 0) {
                long x = Long.parseLong(st.nextToken());
                long y = Long.parseLong(st.nextToken());
                mx = Math.max(mx, x * x + y * y);
            }
            dist[i] = mx;
        }
        Arrays.sort(dist);
        System.out.println(dist[k - 1] + ".00");
    }
}
