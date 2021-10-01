import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a, b, n, m, i, y, x, num, r, k, ty, tx;
        char d;
        int[] dy = {1, 0, -1, 0};
        int[] dx = {0, 1, 0, -1};
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[][] map = new int[b + 1][a + 1];
        int[][] robot = new int[n + 1][3];
        for (i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            d = st.nextToken().charAt(0);
            map[y][x] = i;
            robot[i][1] = x;
            robot[i][0] = y;
            if (d == 'N') robot[i][2] = 0;
            if (d == 'E') robot[i][2] = 1;
            if (d == 'S') robot[i][2] = 2;
            if (d == 'W') robot[i][2] = 3;
        }
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            num = Integer.parseInt(st.nextToken());
            d = st.nextToken().charAt(0);
            r = Integer.parseInt(st.nextToken());
            if (d == 'L') {
                robot[num][2] = (robot[num][2] + r * 3) % 4;
            } else if (d == 'R') {
                robot[num][2] = (robot[num][2] + r) % 4;
            } else {
                k = robot[num][2];
                while (r-- > 0) {
                    ty = robot[num][0] + dy[k];
                    tx = robot[num][1] + dx[k];
                    if (ty <= 0 || ty > b || tx <= 0 || tx > a) {
                        System.out.println("Robot " + num + " crashes into the wall");
                        return;
                    } else if (map[ty][tx] != 0) {
                        System.out.println("Robot " + num + " crashes into robot " + map[ty][tx]);
                        return;
                    } else {
                        map[robot[num][0]][robot[num][1]] = 0;
                        map[ty][tx] = num;
                        robot[num][0] = ty;
                        robot[num][1] = tx;
                    }

                }
            }
        }
        System.out.println("OK");
    }
}
