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
        int l = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        boolean[][] map = new boolean[l][w];
        for (int i = 0; i < l; i++) {
            String str = br.readLine();
            for (int j = 0; j < w; j++) if (str.charAt(j) == 'L') map[i][j] = true;
        }
        int mx = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j]) {
                    Queue<pos> q = new LinkedList<>();
                    boolean[][] chk = new boolean[l][w];
                    q.add(new pos(i, j));
                    chk[i][j] = true;
                    int cnt = -1;
                    while (!q.isEmpty()) {
                        int sz = q.size();
                        while (sz-- > 0) {
                            pos p = q.poll();
                            for (int k = 0; k < 4; k++) {
                                int ny = p.y + dy[k];
                                int nx = p.x + dx[k];
                                if (ny < 0 || ny > l - 1 || nx < 0 || nx > w - 1) continue;
                                if (chk[ny][nx] || !map[ny][nx]) continue;
                                chk[ny][nx] = true;
                                q.add(new pos(ny, nx));
                            }
                        }
                        cnt++;
                    }
                    mx = Math.max(mx, cnt);
                }
            }
        }
        System.out.println(mx);
    }
}

class pos {
    int y, x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
