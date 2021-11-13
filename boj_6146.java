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
        int y = Integer.parseInt(st.nextToken()) + 500;
        int x = Integer.parseInt(st.nextToken()) + 500;
        boolean[][] map = new boolean[1001][1001];
        boolean[][] chk = new boolean[1001][1001];
        int n = Integer.parseInt(st.nextToken());
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            int ty = Integer.parseInt(st.nextToken()) + 500;
            int tx = Integer.parseInt(st.nextToken()) + 500;
            map[ty][tx] = true;
        }
        Queue<pos> q = new LinkedList<>();
        q.add(new pos(500, 500));
        chk[500][500] = true;
        int cnt = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                pos p = q.poll();
                if (p.y == y && p.x == x) {
                    System.out.println(cnt);
                    return;
                }
                for (int j = 0; j < 4; j++) {
                    int ny = p.y + dy[j];
                    int nx = p.x + dx[j];
                    if (ny < 0 || ny > 1000 || nx < 0 || nx > 1000) continue;
                    if (chk[ny][nx]) continue;
                    chk[ny][nx] = true;
                    if (!map[ny][nx]) q.add(new pos(ny, nx));
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
