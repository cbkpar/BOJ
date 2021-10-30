import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

    static int[][] map;
    static int mx;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            map = new int[5][9];
            int cnt = 0;
            for (int i = 0; i < 5; i++) {
                String str = br.readLine();
                for (int j = 0; j < 9; j++) {
                    if (str.charAt(j) == '#') {
                        map[i][j] = 2;
                    } else if (str.charAt(j) == 'o') {
                        map[i][j] = 1;
                        cnt++;
                    }
                }
            }
            mx = 0;
            btr(0);
            sb.append((cnt - mx) + " " + mx + "\n");
            if (t != 0) br.readLine();
        }
        System.out.println(sb);
    }

    private static void btr(int t) {
        mx = Math.max(mx, t);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                if (map[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        int ty = i + dy[k] * 2;
                        int tx = j + dx[k] * 2;
                        if (ty < 0 || ty > 4 || tx < 0 || tx > 8) continue;
                        if (map[ty][tx] != 0) continue;
                        if (map[ny][nx] == 1) {
                            map[ny][nx] = 0;
                            map[i][j] = 0;
                            map[ty][tx] = 1;
                            btr(t + 1);
                            map[ty][tx] = 0;
                            map[i][j] = 1;
                            map[ny][nx] = 1;
                        }
                    }
                }
            }
        }
    }
}
