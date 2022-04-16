import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                int iSum = 0;
                for (int k = 0; k < 3; k++) {
                    iSum += Integer.parseInt(st.nextToken());
                }
                map[i][j] = iSum;
            }
        }
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = (map[i][j] >= T * 3 ? 1 : 0);
            }
        }
        boolean[][] bCheck = new boolean[n][m];
        int iCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bCheck[i][j]) continue;
                if (map[i][j] == 1) {
                    Queue<pos> q = new LinkedList<>();
                    bCheck[i][j] = true;
                    ++iCount;
                    q.add(new pos(i, j));
                    while (!q.isEmpty()) {
                        pos p = q.poll();
                        for (int k = 0; k < 4; k++) {
                            int ny = p.y + dy[k];
                            int nx = p.x + dx[k];
                            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                            if (bCheck[ny][nx] || map[ny][nx] == 0) continue;
                            bCheck[ny][nx] = true;
                            q.add(new pos(ny, nx));
                        }
                    }
                }
            }
        }
        System.out.println(iCount);
    }
}

class pos {
    int y, x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
