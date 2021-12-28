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
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        boolean[][] isfood = new boolean[n][m];
        while (k-- > 0) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken()) - 1;
            isfood[r][c] = true;
        }
        boolean[][] visited = new boolean[n][m];
        int mx = 0;
        Queue<pos> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isfood[i][j] && !visited[i][j]) {
                    q.add(new pos(i, j));
                    int cnt = 1;
                    visited[i][j] = true;
                    while (!q.isEmpty()) {
                        pos p = q.poll();
                        for (int t = 0; t < 4; t++) {
                            int ty = p.y + dy[t];
                            int tx = p.x + dx[t];
                            if (ty < 0 || ty > n - 1 || tx < 0 || tx > m - 1) continue;
                            if (visited[ty][tx]) continue;
                            visited[ty][tx] = true;
                            if (isfood[ty][tx]) {
                                cnt++;
                                q.add(new pos(ty, tx));
                            }
                        }
                    }
                    mx = Math.max(mx, cnt);
                }
            }
        }
        System.out.println(mx);
    }
}

class pos {
    int y;
    int x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
