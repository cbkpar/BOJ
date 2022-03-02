import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, z, m;
    static boolean[] obstacles;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        obstacles = new boolean[n];
        z = Integer.parseInt(st.nextToken()) - 1;
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        while (m-- > 0) obstacles[Integer.parseInt(st.nextToken()) - 1] = true;
        System.out.println(findk());
    }

    private static int findk() {
        for (int step = 1; step < n; step++) {
            int now = 0;
            boolean[] visited = new boolean[n];
            visited[0] = true;
            while (true) {
                if (now == z) return step;
                now = (now + step) % n;
                if (obstacles[now] || visited[now]) break;
            }
        }
        return -1;
    }
}
