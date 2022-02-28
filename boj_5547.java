import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dx = {-1, 0, -1, 0, -1, 1};
        int[] dy = {-1, -1, 1, 1, 0, 0};
        StringTokenizer st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int[][] map = new int[h + 2][w + 2];
        for (int i = 1; i <= h; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= w; j++) map[i][j] = Integer.parseInt(st.nextToken());
        }
        boolean chk[][] = new boolean[h + 2][w + 2];
        Queue<pos> q = new LinkedList<>();
        q.add(new pos(0, 0));
        chk[0][0] = true;
        int cnt = 0;
        while (!q.isEmpty()) {
            pos p = q.poll();
            for (int i = 0; i < 6; i++) {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i] + (p.y % 2 == 1 && i < 4 ? 1 : 0);
                if (ny < 0 || ny > h + 1 || nx < 0 || nx > w + 1) continue;
                if (map[ny][nx] == 1) {
                    cnt++;
                    continue;
                }
                if (chk[ny][nx]) continue;
                chk[ny][nx] = true;
                q.add(new pos(ny, nx));
            }
        }
        System.out.println(cnt);
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
