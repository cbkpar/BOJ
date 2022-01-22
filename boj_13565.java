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
        boolean[][] map = new boolean[n][m];
        boolean[][] chk = new boolean[n][m];
        boolean ispossible = false;
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) map[i][j] = str.charAt(j) == '0' ? true : false;
        }
        Queue<pos> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            chk[0][i] = true;
            if (map[0][i]) q.add(new pos(0, i));
        }
        while (!q.isEmpty()) {
            pos p = q.poll();
            if (p.y == n - 1) {
                ispossible = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                if (chk[ny][nx]) continue;
                chk[ny][nx] = true;
                if (map[ny][nx]) q.add(new pos(ny, nx));
            }
        }
        System.out.println(ispossible ? "YES" : "NO");
    }
}

class pos {
    int y, x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
