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
        for (int T = 1; T <= t; T++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            boolean[][] map = new boolean[n][m];
            for (int i = 0; i < n; i++) {
                String str = br.readLine();
                for (int j = 0; j < m; j++) if (str.charAt(j) == 'O') map[i][j] = true;
            }
            Queue<pos> q = new LinkedList<>();
            boolean[][] chk = new boolean[n][m];
            if (map[0][0]) {
                chk[0][0] = true;
                q.add(new pos(0, 0));
            }
            while (!q.isEmpty()) {
                pos p = q.poll();
                for (int i = 0; i < 4; i++) {
                    int ny = p.y + dy[i];
                    int nx = p.x + dx[i];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                    if (chk[ny][nx]) continue;
                    if (map[ny][nx]) {
                        chk[ny][nx] = true;
                        q.add(new pos(ny, nx));
                    }
                }
            }
            sb.append("Case: " + T + "\n");
            sb.append("+");
            for (int i = 0; i < m; i++) sb.append("---+");
            sb.append("\n");
            for (int i = 0; i < n; i++) {
                sb.append("|");
                for (int j = 0; j < m; j++) {
                    if (chk[i][j]) {
                        sb.append(" M |");
                    } else {
                        if (!map[i][j]) {
                            sb.append(" X |");
                        } else {
                            sb.append("   |");
                        }
                    }
                }
                sb.append("\n+");
                for (int j = 0; j < m; j++) sb.append("---+");
                sb.append("\n");
            }
            sb.append("Minions can" + (chk[n - 1][m - 1] ? "" : "not") + " cross the room\n");
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
