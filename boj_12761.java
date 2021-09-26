import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, m, a, b, cnt, sz, i;
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        boolean[] chk = new boolean[100001];
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        cnt = 0;
        while (!q.isEmpty()) {
            sz = q.size();
            for (i = 0; i < sz; i++) {
                int p = q.poll();
                if (p == m) {
                    System.out.println(cnt);
                    return;
                }
                if (p - 1 >= 0) {
                    if (!chk[p - 1]) {
                        chk[p - 1] = true;
                        q.add(p - 1);
                    }
                }
                if (p + 1 <= 100000) {
                    if (!chk[p + 1]) {
                        chk[p + 1] = true;
                        q.add(p + 1);
                    }
                }
                if (p - a >= 0) {
                    if (!chk[p - a]) {
                        chk[p - a] = true;
                        q.add(p - a);
                    }
                }
                if (p + a <= 100000) {
                    if (!chk[p + a]) {
                        chk[p + a] = true;
                        q.add(p + a);
                    }
                }
                if (p - b >= 0) {
                    if (!chk[p - b]) {
                        chk[p - b] = true;
                        q.add(p - b);
                    }
                }
                if (p + b <= 100000) {
                    if (!chk[p + b]) {
                        chk[p + b] = true;
                        q.add(p + b);
                    }
                }
                if (p * a <= 100000) {
                    if (!chk[p * a]) {
                        chk[p * a] = true;
                        q.add(p * a);
                    }
                }
                if (p * b <= 100000) {
                    if (!chk[p * b]) {
                        chk[p * b] = true;
                        q.add(p * b);
                    }
                }
            }
            cnt++;
        }
    }
}
