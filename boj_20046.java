import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(dijkstra(map, n, m));
    }

    private static int dijkstra(int[][] map, int n, int m) {
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        boolean[][] chk = new boolean[n][m];
        PriorityQueue<pos> pq = new PriorityQueue<>();
        if (map[0][0] == -1) return -1;
        pq.add(new pos(0, 0, map[0][0]));
        chk[0][0] = true;
        while (!pq.isEmpty()) {
            pos p = pq.poll();
            if (p.r == n - 1 && p.c == m - 1) return p.w;
            for (int i = 0; i < 4; i++) {
                int ny = p.r + dy[i];
                int nx = p.c + dx[i];
                if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                if (chk[ny][nx] || map[ny][nx] == -1) continue;
                chk[ny][nx] = true;
                pq.add(new pos(ny, nx, p.w + map[ny][nx]));
            }
        }
        return -1;
    }

    private static class pos implements Comparable<pos> {
        int r;
        int c;
        int w;

        public pos(int r, int c, int w) {
            this.r = r;
            this.c = c;
            this.w = w;
        }

        @Override
        public int compareTo(pos o) {
            return this.w - o.w;
        }
    }
}
