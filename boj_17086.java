import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[][] map = new boolean[n][m];
        ArrayList<pos> shark = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                if (st.nextToken().charAt(0) == '1') {
                    map[i][j] = true;
                    shark.add(new pos(i, j));
                }
            }
        }
        int ans = 0;
        int sz = shark.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!map[i][j]) {
                    int dist = Integer.MAX_VALUE;
                    for (int k = 0; k < sz; k++) {
                        dist = Math.min(dist, Math.max(Math.abs(shark.get(k).y - i), Math.abs(shark.get(k).x - j)));
                    }
                    ans = Math.max(ans, dist);
                }
            }
        }
        System.out.println(ans);
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
