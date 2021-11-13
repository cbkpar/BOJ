import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int n, m, sz, total;
    static int mi = Integer.MAX_VALUE;
    static int[][] map;
    static int[] virus;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};
    static ArrayList<pos> arr = new ArrayList<>();

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][n];
        virus = new int[m];
        total = n * n;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int t = Integer.parseInt(st.nextToken());
                if (t == 1) {
                    map[i][j] = 1;
                    total--;
                } else if (t == 2) {
                    arr.add(new pos(i, j));
                }
            }
        }
        sz = arr.size();
        comb(0, 0);
        System.out.println(mi == Integer.MAX_VALUE ? "-1" : mi);
    }

    private static void comb(int k, int s) {
        if (s == m) {
            bfs();
            return;
        }
        for (int i = k; i < sz; i++) {
            virus[s] = i;
            comb(i + 1, s + 1);
        }
    }

    private static void bfs() {
        int[][] tmap = new int[n][n];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) tmap[i][j] = map[i][j];
        int cnt = -1;
        int changed = 0;
        Queue<pos> q = new LinkedList<>();
        for (int v : virus){
            q.add(arr.get(v));
            tmap[arr.get(v).y][arr.get(v).x] =  1;
            changed++;
        }
        while (!q.isEmpty()) {
            cnt++;
            int qsz = q.size();
            for (int i = 0; i < qsz; i++) {
                pos p = q.poll();
                for (int j = 0; j < 4; j++) {
                    int ny = p.y + dy[j];
                    int nx = p.x + dx[j];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1) continue;
                    if (tmap[ny][nx] != 0) continue;
                    tmap[ny][nx] = 1;
                    changed++;
                    q.add(new pos(ny, nx));
                }
            }
        }
        if (total == changed) mi = Math.min(mi, cnt);
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
