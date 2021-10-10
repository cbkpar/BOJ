import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[][] map;
    static int n, mx;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dy = {1, 0};
        int[] dx = {0, 1};
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < n; j++) {
                if (str.charAt(j) == 'C') {
                    map[i][j] = 1;
                } else if (str.charAt(j) == 'P') {
                    map[i][j] = 2;
                } else if (str.charAt(j) == 'Y') {
                    map[i][j] = 3;
                } else {
                    map[i][j] = 4;
                }
            }
        }
        mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 2; k++) {
                    int ty = i + dy[k];
                    int tx = j + dx[k];
                    if (ty > n - 1 || tx > n - 1) continue;
                    int tmp = map[i][j];
                    map[i][j] = map[ty][tx];
                    map[ty][tx] = tmp;
                    calc();
                    tmp = map[i][j];
                    map[i][j] = map[ty][tx];
                    map[ty][tx] = tmp;
                }
            }
        }
        System.out.println(mx);
    }

    private static void calc() {
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            for (int j = 1; j < n; j++) {
                if (map[i][j] == map[i][j - 1]) {
                    cnt++;
                    mx = Math.max(mx, cnt);
                } else {
                    cnt = 1;
                }
            }

        }
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            for (int j = 1; j < n; j++) {
                if (map[j][i] == map[j - 1][i]) {
                    cnt++;
                    mx = Math.max(mx, cnt);
                } else {
                    cnt = 1;
                }
            }

        }
    }
}
