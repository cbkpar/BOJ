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
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                if (str.charAt(j) == '.') {
                    map[i][j] = 1;
                } else if (str.charAt(j) == 'k') {
                    map[i][j] = 2;
                } else if (str.charAt(j) == 'v') {
                    map[i][j] = 3;
                }
            }
        }
        int sheep = 0;
        int wolf = 0;
        Queue<pos> q = new LinkedList<>();
        boolean[][] chk = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!chk[i][j]) {
                    chk[i][j] = true;
                    int t_sheep = 0;
                    int t_wolf = 0;
                    q.add(new pos(i, j));
                    while (!q.isEmpty()) {
                        pos p = q.poll();
                        if (map[p.y][p.x] == 2) t_sheep++;
                        if (map[p.y][p.x] == 3) t_wolf++;
                        for (int k = 0; k < 4; k++) {
                            int ny = p.y + dy[k];
                            int nx = p.x + dx[k];
                            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                            if (chk[ny][nx]) continue;
                            chk[ny][nx] = true;
                            if (map[ny][nx] != 0) q.add(new pos(ny, nx));
                        }
                    }
                    if (t_sheep > t_wolf) {
                        sheep += t_sheep;
                    } else {
                        wolf += t_wolf;
                    }
                }
            }
        }
        System.out.println(sheep + " " + wolf);
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
