import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        ArrayList<Integer> teleport[] = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) teleport[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            teleport[x].add(y);
            teleport[y].add(x);
        }
        boolean chk[] = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        chk[s] = true;
        int time = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                int p = q.poll();
                if (p == e) {
                    System.out.println(time);
                    return;
                }
                if (p > 0 && !chk[p - 1]) {
                    q.add(p - 1);
                    chk[p - 1] = true;
                }
                if (p < n && !chk[p + 1]) {
                    q.add(p + 1);
                    chk[p + 1] = true;
                }
                for (int t : teleport[p]) {
                    if (!chk[t]) {
                        q.add(t);
                        chk[t] = true;
                    }
                }

            }
            ++time;
        }
    }
}
