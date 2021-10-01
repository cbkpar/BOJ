import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, m, i, t, cnt;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[][] medal = new int[n + 1][3];
        for (i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            t = Integer.parseInt(st.nextToken());
            medal[t][0] = Integer.parseInt(st.nextToken());
            medal[t][1] = Integer.parseInt(st.nextToken());
            medal[t][2] = Integer.parseInt(st.nextToken());
        }
        cnt = 1;
        for (i = 1; i <= n; i++) {
            if (i == m) continue;
            if (medal[i][0] > medal[m][0]) {
                cnt++;
                continue;
            }
            if (medal[i][0] != medal[m][0]) continue;
            if (medal[i][1] > medal[m][1]) {
                cnt++;
                continue;
            }
            if (medal[i][1] != medal[m][1]) continue;
            if (medal[i][2] > medal[m][2]) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
