import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, k, t, i, j, sz, cnt, p, tmp;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        t = 0;
        String str = br.readLine();
        for (i = 0; i < n; i++) if (str.charAt(i) == 'T') t++;
        Queue<Integer> q = new LinkedList<>();
        q.add(t);
        boolean[] chk = new boolean[n + 1];
        chk[t] = true;
        cnt = 0;
        while (!q.isEmpty()) {
            sz = q.size();
            for (i = 0; i < sz; i++) {
                p = q.poll();
                if (p == n) {
                    System.out.println(cnt);
                    return;
                }
                for (j = 0; j <= p; j++) {
                    if (j == k + 1) break;
                    if (k - j > n - p) continue;
                    tmp = p + k - j * 2;
                    if (tmp < 0 || tmp > n) continue;
                    if (chk[tmp]) continue;
                    chk[tmp] = true;
                    q.add(tmp);
                }
            }
            cnt++;
        }
        System.out.println("-1");
    }
}
