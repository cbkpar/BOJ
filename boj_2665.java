import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        int n = Integer.parseInt(br.readLine());
        int[][] map = new int[n][n];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < n; j++) map[i][j] = str.charAt(j) - '0';
        }
        Queue<pos> white = new LinkedList<>();
        Queue<pos> black = new LinkedList<>();
        white.add(new pos(0, 0));
        int cnt = 0;
        boolean[][] chk = new boolean[n][n];
        chk[0][0] = true;
        while (!white.isEmpty()) {
            while (!white.isEmpty()) {
                pos p = white.poll();
                if (p.y == n - 1 && p.x == n - 1) {
                    System.out.println(cnt);
                    return;
                }
                for (int i = 0; i < 4; i++) {
                    int ny = p.y + dy[i];
                    int nx = p.x + dx[i];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1) continue;
                    if (chk[ny][nx]) continue;
                    chk[ny][nx] = true;
                    if (map[ny][nx] == 1) {
                        white.add(new pos(ny, nx));
                    } else {
                        black.add(new pos(ny, nx));
                    }
                }
            }
            while (!black.isEmpty()) {
                pos p = black.poll();
                chk[p.y][p.x] = true;
                white.add(new pos(p.y, p.x));
            }
            cnt++;
        }
    }
}

class pos {
    int y, x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
