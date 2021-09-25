import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, j, t, m, c, mx;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[] cost = new int[6];
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < 6; i++) cost[i] = Integer.parseInt(st.nextToken());
        int[][] num = new int[n][2];
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < n; i++) {
            num[i][0] = Integer.parseInt(st.nextToken()) - 1;
            num[i][1] = cost[num[i][0]];
        }
        mx = 0;
        for (i = 1; i < (1 << 6); i++) {
            t = c = 0;
            for (j = 0; j < n; j++) {
                if (((1 << num[j][0]) & i) == 0) continue;
                if (t + num[j][1] > m) break;
                t += num[j][1];
                c++;
            }
            mx = Math.max(mx, c);
        }
        System.out.println(mx);
    }
}
