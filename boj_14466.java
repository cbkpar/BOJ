import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] par;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, q, r, a, b, c, d, i, j, k, s, ny, nx;
        int[] dy = {1, -1, 0, 0};
        int[] dx = {0, 0, 1, -1};
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        par = new int[n * n];
        for (i = 1; i < n * n; i++) par[i] = i;
        boolean[][][] map = new boolean[n][n][4];
        while (r-- > 0) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken()) - 1;
            b = Integer.parseInt(st.nextToken()) - 1;
            c = Integer.parseInt(st.nextToken()) - 1;
            d = Integer.parseInt(st.nextToken()) - 1;
            if (a == c) {
                if (b > d) {
                    map[a][d][2] = map[c][b][3] = true;
                } else {
                    map[a][b][2] = map[c][d][3] = true;
                }
            } else {
                if (a > c) {
                    map[c][b][0] = map[a][d][1] = true;
                } else {
                    map[a][b][0] = map[c][d][1] = true;
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < 4; k++) {
                    ny = i + dy[k];
                    nx = j + dx[k];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1) continue;
                    if (map[i][j][k]) continue;
                    union(find(i * n + j), find(ny * n + nx));
                }
            }
        }
        ArrayList<pos> arr = new ArrayList<>();
        for (i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken()) - 1;
            b = Integer.parseInt(st.nextToken()) - 1;
            arr.add(new pos(a, b));
        }
        s = 0;
        for (i = 0; i < q; i++) {
            a = find(arr.get(i).y * n + arr.get(i).x);
            for (j = i + 1; j < q; j++) {
                b = find(arr.get(j).y * n + arr.get(j).x);
                if (a != b) s++;
            }
        }
        System.out.println(s);
    }

    static int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a > b) {
            par[b] = a;
        } else if (a < b) {
            par[a] = b;
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
