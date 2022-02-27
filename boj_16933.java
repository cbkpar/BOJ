import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] dy = {1, 0, -1, 0};
        int[] dx = {0, 1, 0, -1};
        boolean[][][] visited = new boolean[n][m][k + 1];
        char[][] map = new char[n][m];
        for (int i = 0; i < n; i++) map[i] = br.readLine().toCharArray();
        Queue<node> q = new LinkedList<>();
        q.add(new node(0, 0, 0, 1));
        visited[0][0][0] = true;
        boolean day = true;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                int y = q.peek().y;
                int x = q.peek().x;
                int w = q.peek().w;
                int d = q.poll().d;
                if (y == n - 1 && x == m - 1) {
                    System.out.println(d);
                    return;
                }
                for (int j = 0; j < 4; j++) {
                    int ny = y + dy[j];
                    int nx = x + dx[j];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                    if (map[ny][nx] == '1') {
                        if (w >= k) continue;
                        if (visited[ny][nx][w + 1]) continue;
                        if (day) {
                            visited[ny][nx][w + 1] = true;
                            q.add(new node(ny, nx, w + 1, d + 1));
                        } else {
                            q.add(new node(y, x, w, d + 1));
                        }
                    } else {
                        if (visited[ny][nx][w]) continue;
                        visited[ny][nx][w] = true;
                        q.add(new node(ny, nx, w, d + 1));
                    }
                }
            }
            day = !day;
        }
        System.out.println("-1");
    }
}

class node {
    int y, x, w, d;

    public node(int y, int x, int w, int d) {
        this.y = y;
        this.x = x;
        this.w = w;
        this.d = d;
    }
}
