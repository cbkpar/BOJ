import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dy = {-2, -2, -1, 1, 2, 2, 1, -1};
        int[] dx = {-1, 1, 2, 2, 1, -1, -2, -2};
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[][] map = new int[n][m];
        boolean[][] chk = new boolean[n][m];
        int ty = 0;
        int tx = 0;
        Queue<pos> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                if (str.charAt(j) == '*') {
                    map[i][j] = 1;
                } else if (str.charAt(j) == 'K') {
                    chk[i][j] = true;
                    q.add(new pos(i, j));
                } else if (str.charAt(j) == 'H') {
                    ty = i;
                    tx = j;
                }
            }
        }
        int cnt = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                pos p = q.poll();
                if (p.y == ty && p.x == tx) {
                    System.out.println(cnt);
                    return;
                }
                for (int j = 0; j < 8; j++) {
                    int ny = p.y + dy[j];
                    int nx = p.x + dx[j];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                    if (chk[ny][nx]) continue;
                    chk[ny][nx] = true;
                    q.add(new pos(ny, nx));
                }
            }
            cnt++;
        }
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
