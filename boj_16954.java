import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i, j, sz, ny, nx;
        int[][] map = new int[8][8];
        int[] dy = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int[] dx = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        for (i = 0; i < 8; i++) {
            String str = br.readLine();
            for (j = 0; j < 8; j++) {
                if (str.charAt(j) == '#') map[i][j] = 1;
            }
        }
        Queue<pos> q = new LinkedList<>();
        q.add(new pos(7, 0));
        while (!q.isEmpty()) {
            sz = q.size();
            boolean[][] chk = new boolean[8][8];
            for (i = 0; i < sz; i++) {
                pos p = q.poll();
                if (p.y == 0 && p.x == 7) {
                    System.out.println("1");
                    return;
                }
                if (map[p.y][p.x] == 1) continue;
                for (j = 0; j < 9; j++) {
                    ny = p.y + dy[j];
                    nx = p.x + dx[j];
                    if (ny < 0 || ny > 7 || nx < 0 || nx > 7) continue;
                    if (chk[ny][nx]) continue;
                    chk[ny][nx] = true;
                    if (map[ny][nx] == 1) continue;
                    q.add(new pos(ny, nx));
                }
            }
            for (i = 0; i < 8; i++) {
                for (j = 6; j >= 0; j--) {
                    if (map[j][i] == 1) {
                        map[j + 1][i] = 1;
                        map[j][i] = 0;
                    }
                }
            }
        }
        System.out.println("0");

    }
}

class pos {
    int y, x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
