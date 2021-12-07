import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            String[] map = new String[h];
            for (int i = 0; i < h; i++) map[i] = br.readLine();
            boolean[][] chk = new boolean[h][w];
            Queue<pos> q = new LinkedList<>();
            int cnt = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (!chk[i][j] && map[i].charAt(j) == '#') {
                        q.add(new pos(i, j));
                        chk[i][j] = true;
                        cnt++;
                    }
                    while (!q.isEmpty()) {
                        pos p = q.poll();
                        for (int k = 0; k < 4; k++) {
                            int ny = p.y + dy[k];
                            int nx = p.x + dx[k];
                            if (ny < 0 || ny > h - 1 || nx < 0 || nx > w - 1) continue;
                            if (chk[ny][nx]) continue;
                            chk[ny][nx] = true;
                            if (map[ny].charAt(nx) == '#') {
                                q.add(new pos(ny, nx));
                            }
                        }
                    }
                }
            }
            sb.append(cnt + "\n");
        }
        System.out.println(sb);
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
