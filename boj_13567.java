import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] map = new int[n + 1][n + 1];
        int[] dy = {1, 0, -1, 0};
        int[] dx = {0, -1, 0, 1};
        int ny = 0;
        int nx = 0;
        int nd = 3;
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            if (st.nextToken().equals("MOVE")) {
                int t = Integer.parseInt(st.nextToken());
                int ty = ny + dy[nd] * t;
                int tx = nx + dx[nd] * t;
                if (ty < 0 || ty > n || tx < 0 || tx > n) {
                    System.out.println("-1");
                    return;
                }
                ny = ty;
                nx = tx;
            } else {
                int t = Integer.parseInt(st.nextToken());
                if (t == 1) {
                    nd = (nd + 3) % 4;
                } else {
                    nd = (nd + 1) % 4;
                }
            }
        }
        System.out.println(nx + " " + ny);
    }
}
