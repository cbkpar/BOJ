import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int r, c, i, j, k, ny, nx, a, b, sheep, wolf;
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        int[][] map = new int[r][c];
        boolean[][] chk = new boolean[r][c];
        for (i = 0; i < r; i++) {
            String str = br.readLine();
            for (j = 0; j < c; j++) {
                if (str.charAt(j) == '#') {
                    map[i][j] = 1;
                } else if (str.charAt(j) == 'v') {
                    map[i][j] = 2;
                } else if (str.charAt(j) == 'o') {
                    map[i][j] = 3;
                }
            }
        }
        sheep = wolf = 0;
        Queue<pos> q = new LinkedList<>();
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (map[i][j] != 1 && !chk[i][j]) {
                    chk[i][j] = true;
                    q.add(new pos(i, j));
                    a = b = 0;
                    while (!q.isEmpty()) {
                        pos p = q.poll();
                        if (map[p.y][p.x] == 2) a++;
                        if (map[p.y][p.x] == 3) b++;
                        for (k = 0; k < 4; k++) {
                            ny = p.y + dy[k];
                            nx = p.x + dx[k];
                            if (ny < 0 || ny > r - 1 || nx < 0 || nx > c - 1) continue;
                            if (chk[ny][nx]) continue;
                            chk[ny][nx] = true;
                            if(map[ny][nx]==1) continue;
                            q.add(new pos(ny, nx));
                        }
                    }
                    if (a >= b) {
                        wolf += a;
                    } else {
                        sheep += b;
                    }
                }
            }
        }
        System.out.println(sheep + " " + wolf);
    }
}

class pos {
    int y, x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
