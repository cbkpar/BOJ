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
        int z = Integer.parseInt(st.nextToken()) - 1;
        int m = Integer.parseInt(st.nextToken());
        boolean[] obstacles = new boolean[n];
        st = new StringTokenizer(br.readLine());
        while (m-- > 0) obstacles[Integer.parseInt(st.nextToken()) - 1] = true;
        for (int step = 1; step < n; step++) {
            Queue<Integer> q = new LinkedList<>();
            boolean[] visited = new boolean[n];
            visited[0] = true;
            q.add(0);
            while (!q.isEmpty()) {
                int p = q.poll();
                if (p == z) {
                    System.out.println(step);
                    return;
                }
                p = (p + step) % n;
                if (obstacles[p] || visited[p]) continue;
                q.add(p);
            }
        }
    }
}
