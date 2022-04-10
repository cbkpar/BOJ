import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int f = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        boolean chk[] = new boolean[n + 1];
        if (k > 0) {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < k; i++) {
                chk[Integer.parseInt(st.nextToken())] = true;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        chk[s] = true;
        int time = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                int p = q.poll();
                if (p == d) {
                    System.out.println(time);
                    return;
                }
                if (p - b > 0 && !chk[p - b]) {
                    q.add(p - b);
                    chk[p - b] = true;
                }
                if (p + f <= n && !chk[p + f]) {
                    q.add(p + f);
                    chk[p + f] = true;
                }

            }
            ++time;
        }
        System.out.println("BUG FOUND");
    }
}
