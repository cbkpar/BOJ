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
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) break;
            char[][] map = new char[n][m];
            for (int i = 0; i < n; i++) {
                String str = br.readLine();
                for (int j = 0; j < m; j++) map[i][j] = str.charAt(j);
            }
            boolean[][] visited = new boolean[n][m];
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == '@' && !visited[i][j]) {
                        cnt++;
                        Queue<pos> q = new LinkedList<>();
                        q.add(new pos(i, j));
                        visited[i][j] = true;
                        while (!q.isEmpty()) {
                            pos p = q.poll();
                            for (int y = -1; y <= 1; y++) {
                                for (int x = -1; x <= 1; x++) {
                                    int ny = p.y + y;
                                    int nx = p.x + x;
                                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                                    if (!visited[ny][nx]) {
                                        visited[ny][nx] = true;
                                        if (map[ny][nx] == '@') q.add(new pos(ny, nx));
                                    }
                                }
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
