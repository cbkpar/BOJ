import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n, i, j, k, ty, tx, mx, cnt, tcnt, ny, nx;
        n = Integer.parseInt(br.readLine());
        int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
        int[][] map = new int[n][n];
        for (i = 0; i < n; i++) {
            String str = br.readLine();
            for (j = 0; j < n; j++) {
                if (str.charAt(j) == 'W') {
                    map[i][j] = 1;
                } else if (str.charAt(j) == 'B') {
                    map[i][j] = 2;
                }
            }
        }
        ty = tx = 0;
        mx = -1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (map[i][j] == 0) {
                    cnt = 0;
                    for (k = 0; k < 8; k++) {
                        ny = i;
                        nx = j;
                        tcnt = 0;
                        while (true) {
                            ny += dy[k];
                            nx += dx[k];
                            if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1) break;
                            if (map[ny][nx] == 0) break;
                            if (map[ny][nx] == 1) {
                                tcnt++;
                                continue;
                            }
                            cnt += tcnt;
                            break;
                        }
                    }
                    if (cnt != 0) {
                        if (cnt > mx) {
                            mx = cnt;
                            ty = i;
                            tx = j;
                        }
                    }
                }
            }
        }
        if (mx != -1) {
            System.out.println(tx + " " + ty + "\n" + mx);
        } else {
            System.out.println("PASS");
        }
    }
}
